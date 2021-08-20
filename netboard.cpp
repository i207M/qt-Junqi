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
    char arr[2] = {row, col};
    tcpSocket->write(arr, 3);
}

void Netboard::slotNewConnection()
{
    err("Got connection");
    check(tcpSocket == nullptr);

    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);
}

void Netboard::slotRecv()
{
    err("Recv");
    QByteArray arr = tcpSocket->readAll();

    int click_row = arr[0], click_col = arr[1];
    Chessboard::clickPos(click_row, click_col);
}
