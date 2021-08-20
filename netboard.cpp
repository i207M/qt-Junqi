#include "netboard.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Mdebug.h"

Netboard::Netboard(MainWindow *_win, QString ip): Chessboard(_win)
{
    const int PORT = 2077;

    qDebug() << "Netboard init " << ip;
    check(ip != "-1");

    this->is_online = true;
    tcpServer = nullptr;
    tcpSocket = nullptr;
    if(ip == "0") {
        local_player = 1;

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

void Netboard::clickPos(int row, int col)
{
    Chessboard::clickPos(row, col);
    char arr[3] = {2, row, col};
    tcpSocket->write(arr, 3);
}

void Netboard::slotNewConnection()
{
    err("Got connection");
    check(tcpSocket == nullptr);

    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);

    win->connectSuccessfully();

    netGameInit();
    tcpSocket->write()
}

void Netboard::slotRecv()
{
    QByteArray arr = tcpSocket->readAll();
    char ctrl = arr[0];
    err("Recv", ctrl);

    if(ctrl == 0) {
        check(local_player == 2);
        win->connectSuccessfully();
    } else if(ctrl == 1) {
        syncBoard(arr.mid(1));
    } else if(ctrl == 2) {
        ;
    } else if(ctrl == 3) {
        int click_row = arr[0], click_col = arr[1];
        Chessboard::clickPos(click_row, click_col);
    } else if(ctrl == 4) {
        win->actionAdmitDefeat();
    } else if(ctrl == 5) {
        err("Opponent timed out.");
    } else {
        err("Error CTRL");
    }
}

void Netboard::netGameInit()
{
    static char chess_data[50 * 7];
    int cnt = 0;

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
    err("syncBoard");

    this->displayAll();
}
