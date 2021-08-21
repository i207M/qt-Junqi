#include "netboard.h"

#include "windows.h"

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

    tcpServer = nullptr;
    tcpSocket = nullptr;
    if(ip == "0") {
        local_player = 1;
        initBoard();
        displayAll();
        win->log("Chessboard Initialized.");

        tcpServer = new QTcpServer(this);
        tcpServer->listen(QHostAddress::Any, PORT);
        connect(tcpServer, &QTcpServer::newConnection, this, &Netboard::slotNewConnection);
    } else {
        local_player = 2;

        tcpSocket = new QTcpSocket(this);
        tcpSocket->connectToHost(QHostAddress(ip), PORT);
        connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);
    }
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
            check(tcpServer == nullptr);
            win->connectSuccessfully();
        } else if(ctrl == 101) {
            syncBoard(arr.mid(i, 50 * 7));
            i += 50 * 7;
        } else if(ctrl == 102) {
            netPressStart(arr[i++]);
        } else if (ctrl == 104) {
            int click_row = arr[i++], click_col = arr[i++];
            Chessboard::clickPos(click_row, click_col);
        } else if(ctrl == 105) {
            // TODO: cannot admit defeat as your opponent
            // win->actionAdmitDefeat();
        } else {
            err("Error Ctrl");
        }
    }
}

void Netboard::clickPos(int row, int col)
{
    err("Netboard clickPos", row, col);
    Chessboard::clickPos(row, col);
    char Ctrl4[3] = {104, row, col};
    tcpSocket->write(Ctrl4, 3);
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

    win->log("You Pressed Start.");
    genRandomPrior();

    char Ctrl2[2] = {102, random_prior[0]};
    tcpSocket->write(Ctrl2, 2);

    checkStart();
}

void Netboard::netPressStart(char _random_prior)
{
    win->log("Opponent Pressed Start.");
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
        win->changeYouPlayer(current_player, current_color);
    }
    flip_color[current_player - 1] = p[id].color;
}
