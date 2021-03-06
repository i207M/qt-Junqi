#include "netboard.h"

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "m_debug.h"

Netboard::Netboard(MainWindow *_win, QString ip): Chessboard(_win)
{
    const int PORT = 2077;

    err("Netboard init", ip.toStdString());
    check(ip != "-1");

    is_online = true;
    random_prior[0] = -1, random_prior[1] = -1;
    connect_timer = new QTimer(this);
    send_heart_beat = new QTimer(this);
    recv_heart_beat = new QTimer(this);

    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);
    is_connected = false;
    if(ip == "0") {
        local_player = 1;
        initBoard();
        displayAll();
        win->log("Chessboard Initialized.");
        win->log("Waiting for Connection...");

        connect(tcpServer, &QTcpServer::newConnection, this, &Netboard::slotNewConnection);
        tcpServer->listen(QHostAddress::Any, PORT);
    } else {
        local_player = 2;
        connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);
        connect(tcpSocket, &QTcpSocket::disconnected, this, [ = ]() {
            if(this->win->is_game_over) {
                return;
            }
            QMessageBox::warning(this->win,
                                 tr("Warning"),
                                 tr("Disconnected"));
            this->win->restart();
        });
        win->log("Waiting for Connection...");
        tcpSocket->connectToHost(ip, PORT);

        connect(connect_timer, &QTimer::timeout, this, [ = ]() {
            QMessageBox::warning(this->win,
                                 tr("Warning"),
                                 tr("Connection Timeout"));
            this->win->restart();
        });
        connect_timer->start(5000);
    }
    win->changeYouPlayer(local_player, 0);
}

Netboard::~Netboard()
{
    delete tcpServer;
    // delete tcpSocket;
    // delete send_heart_beat;
    // delete recv_heart_beat;
}

void Netboard::slotNewConnection()
{
    err("Got connection");
    if(is_connected) {
        err("Reject multiple connections");
        return;
    }

    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);

    static const char Ctrl0[] = {100};
    tcpSocket->write(Ctrl0, 1);

    is_connected = true;
    sendBoard();
    initHeartBeat();
    win->connectSuccessfully();
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
            is_connected = true;
            connect_timer->stop();
            initHeartBeat();
            win->connectSuccessfully();
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
            // assert: cannot admit defeat as your opponent
            win->gameOver(QString("Admit defeat!\nThe Winner is Player %1.").arg(local_player));
        } else if(ctrl == 106) {
            err("Opponent timed out.");
        } else {
            check(false);
            err("Error Ctrl");
        }
        check(i <= arr.size());
    }
}

void Netboard::clickPos(int row, int col)
{
    if(current_player != local_player) {
        win->log("It is not your turn.");
        return;
    }
    char Ctrl4[] = {104, char(row), char(col)};
    tcpSocket->write(Ctrl4, 3);
    Chessboard::clickPos(row, col);
}

void Netboard::timeOut()
{
    if(current_player == local_player) {
        static const char Ctrl6[] = {106};
        tcpSocket->write(Ctrl6, 1);
    }

    Chessboard::timeOut();
}

void Netboard::tryAdmitDefeat()
{
    const int Admit_Defeat_Limit = 20;

    if(num_turn >= Admit_Defeat_Limit) {
        static const char Ctrl5[] = {105};
        tcpSocket->write(Ctrl5, 1);
        win->gameOver(QString("Admit defeat!\nThe Winner is Player %1.").arg(getOpp(local_player)));
    } else {
        win->log("Failed to Admit Defeat. The number of rounds is less than 20.");
    }
}

bool Netboard::showSelected(int id) const
{
    if(id == select_id and p[id].color == local_color) {
        return true;
    } else {
        return false;
    }
}

void Netboard::localPressStart()
{
    err("localPressStart");
    if(not is_connected) {
        QMessageBox::warning(win,
                             tr("Warning"),
                             tr("Not Connected"));
        return;
    }

    win->log("You pressed start.");
    genRandomPrior();

    char Ctrl2[] = {102, char(random_prior[0])};
    tcpSocket->write(Ctrl2, 2);

    checkStart();
    win->ui->buttonStart->setDisabled(true);
    win->ui->buttonDefeat->setEnabled(true);
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
        p[i].type = Type(int(chess_data[cnt++]));
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
        if(random_prior[0] > random_prior[1] or
                (random_prior[0] == random_prior[1] and local_player == 1)) {
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
    static const char Ctrl3[] = {103};
    tcpSocket->write(Ctrl3, 1);

    delete send_heart_beat;
    send_heart_beat = new QTimer(this);
    connect(send_heart_beat, &QTimer::timeout, this, &Netboard::sendHeartBeat);
    send_heart_beat->start(500);
}

void Netboard::recvHeartBeat()
{
    if(time(0) - last_heart_beat > 2) {
        win->log("Cannot receive heartbeat packet.");
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

void Netboard::debugRandomlyKill()
{
    Chessboard::debugRandomlyKill();
    sendBoard();
}
