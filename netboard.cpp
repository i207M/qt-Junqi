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
    ;
}

void Netboard::slotNewConnection()
{
    ;
}

void Netboard::slotRecv()
{
    ;
}
