#include "netboard.h"

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Mdebug.h"

Netboard::Netboard(MainWindow *_win, QString ip): Chessboard(_win)
{
    const int PORT = 12077;

    qDebug() << "Netboard init " << ip;
    check(ip != "-1");

    is_online = true;
    random_prior[0] = -1, random_prior[1] = -1;

    tcpServer = new QTcpServer(this);
    tcpSocket = nullptr;
    if(ip == "0") {
        local_player = 1;
        initBoard();
        displayAll();
        win->log("Chessboard Initialized.");

        tcpServer->listen(QHostAddress::Any, PORT);
        connect(tcpServer, &QTcpServer::newConnection, this, &Netboard::slotNewConnection);
    } else {
        local_player = 2;

        tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(ip, PORT);
        connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);
    }
    win->changeYouPlayer(local_player, 0);

    send_heart_beat = new QTimer(this);
    recv_heart_beat = new QTimer(this);
}

Netboard::~Netboard()
{
    delete tcpServer;
    if(tcpSocket != nullptr) {
        delete tcpSocket;
    }
    delete send_heart_beat;
    delete recv_heart_beat;
}

void Netboard::slotNewConnection()
{
    err("Got connection");
    if(tcpSocket != nullptr) {
        err("Reject multiple connection");
        return;
    }

    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);

    static const char Ctrl0[1] = {100};
    tcpSocket->write(Ctrl0, 1);
    win->connectSuccessfully();
    initHeartBeat();

    sendBoard();
}

void Netboard::slotRecv()
{
    err("TCP Recv");
    QByteArray arr = tcpSocket->readAll();

    for(int i = 0; i < arr.size(); ) {
        int ctrl = arr[i++];
        err("Ctrl", ctrl);
        if(ctrl == 100) {
            check(local_player == 2);
            win->connectSuccessfully();
            initHeartBeat();
        } else if(ctrl == 101) {
            syncBoard(arr.mid(i, 50 * 7));
            i += 50 * 7;
        } else if(ctrl == 102) {
            netPressStart(arr[i++]);
        } else if(ctrl == 103) {
            last_heart_beat = time(0);
        } else if (ctrl == 104) {
            int click_row = arr[i++], click_col = arr[i++];
            Chessboard::clickPos(click_row, click_col);
        } else if(ctrl == 105) {
            // TODO: cannot admit defeat as your opponent
            // win->actionAdmitDefeat();
        } else if(ctrl == 106) {
            err("Opponent timed out.");
        } else {
            err("Error Ctrl");
        }
    }
}

void Netboard::clickPos(int row, int col)
{
    if(current_player != local_player) {
        win->log("It is not your turn.");
        return;
    }
    Chessboard::clickPos(row, col);
    char Ctrl4[3] = {104, row, col};
    tcpSocket->write(Ctrl4, 3);
}

void Netboard::timeOut()
{
    int t = ++num_time_out[current_player - 1];
    if(current_player == local_player) {
        static const char Ctrl6[1] = {106};
        tcpSocket->write(Ctrl6);
    }

    if(t >= 3) {
        win->gameOver(QString("Time out!\nThe Winner is Player %1.").arg(getOpp()));
    } else {
        win->log(QString("Player %1 timed out.").arg(current_player));
    }
    nextTurn();
}

void Netboard::localPressStart()
{
    err("localPressStart");
    if(tcpSocket == nullptr) {
        QMessageBox::warning(win,
                             tr("Warning"),
                             tr("Client Not Connected."));
        return;
    }

    win->log("You pressed start.");
    genRandomPrior();

    char Ctrl2[2] = {102, random_prior[0]};
    tcpSocket->write(Ctrl2, 2);

    checkStart();
}

void Netboard::netPressStart(int _random_prior)
{
    win->log("Opponent pressed start.");
    random_prior[1] = _random_prior;
    checkStart();
}

void Netboard::sendBoard()
{
    static char chess_data[1 + 50 * 7];

    int cnt = 0;
    chess_data[cnt++] = 101;
    for(int i = 0; i < 50; ++i) {
        chess_data[cnt++] = p[i].id;
        chess_data[cnt++] = p[i].color;
        chess_data[cnt++] = p[i].row;
        chess_data[cnt++] = p[i].col;
        chess_data[cnt++] = p[i].known;
        chess_data[cnt++] = p[i].dead;
        chess_data[cnt++] = int(p[i].type);
    }
    tcpSocket->write(chess_data, sizeof(chess_data));

    for(int i = 0; i < 1 + 50 * 7; ++i) {
        err((int)chess_data[i], ' ');
    }
    err("sendBoard");
}

void Netboard::syncBoard(QByteArray chess_data)
{
    int cnt = 0;
    for(int i = 0; i < 50; ++i) {
        p[i].id = chess_data[cnt++];
        p[i].color = chess_data[cnt++];
        p[i].row = chess_data[cnt++];
        p[i].col = chess_data[cnt++];
        p[i].known = chess_data[cnt++];
        p[i].dead = chess_data[cnt++];
        p[i].type = Type(chess_data[cnt++]);
    }
    win->log("Chessboard Synchronized.");

    displayAll();
}

void Netboard::genRandomPrior()
{
    if(random_prior[0] == -1) {
        srand(time(0));
        random_prior[0] = rand() % 100;
    }
}

void Netboard::checkStart()
{
    if(random_prior[0] == -1 or random_prior[1] == -1) {
        return;
    } else {
        err("Start Prior", random_prior[0], random_prior[1]);
        if(random_prior[0] >= random_prior[1]) {
            // self is the first, but need swap
            current_player = getOpp(local_player);
        } else {
            // opponent is the first, but need swap
            current_player = local_player;
        }
        win->log("Game Start!");
        win->log(QString("Player %1 moves first.").arg(getOpp(current_player)));
        has_start = true;
        nextTurn();
    }
}

void Netboard::tryDetermineColor(int id)
{
    if(flip_color[current_player - 1] == p[id].color) {
        current_color = p[id].color;
        win->log(QString("Color determined: Player %1 is %2").arg(current_player)
                 .arg(current_color == 1 ? "red" : "blue"));

        if(current_player == local_player) {
            local_color = current_color;
        } else {
            local_color = getOpp(current_color);
        }
        win->changeYouPlayer(local_player, local_color);
    }
    flip_color[current_player - 1] = p[id].color;
}

void Netboard::initHeartBeat()
{
    last_heart_beat = time(0);
    sendHeartBeat();
    recvHeartBeat();
}

void Netboard::sendHeartBeat()
{
    static const char Ctrl3[1] = {103};
    tcpSocket->write(Ctrl3, 1);

    delete send_heart_beat;
    send_heart_beat = new QTimer(this);
    connect(send_heart_beat, &QTimer::timeout, this, &Netboard::sendHeartBeat);
    send_heart_beat->start(500);
}

void Netboard::recvHeartBeat()
{
    if(time(0) - last_heart_beat > 1) {
        oppDisconnect();
    }

    delete recv_heart_beat;
    recv_heart_beat = new QTimer(this);
    connect(recv_heart_beat, &QTimer::timeout, this, &Netboard::recvHeartBeat);
    recv_heart_beat->start(1000);
}

void Netboard::stopHeartBeat()
{
    err("stopHeartBeat");
    send_heart_beat->stop();
    recv_heart_beat->stop();
}

void Netboard::oppDisconnect()
{
    win->gameOver("Opponent disconnected.");
}
