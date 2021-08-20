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
    tcpSocket->write(arr, 2);
}

void Netboard::slotNewConnection()
{
    err("Got connection");
    check(tcpSocket == nullptr);

    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);

    win->connectSuccessfully();

    netGameInit();
}

void Netboard::slotRecv()
{
    QByteArray arr = tcpSocket->readAll();
    char ctrl = arr[0];
    err("Recv", ctrl);

    if(ctrl == 0) {
        win->connectSuccessfully();
    } else if(ctrl == 1) {
        syncBoard(arr.mid(1), 0);
    } else if(ctrl == 2) {
        syncBoard(arr.mid(1), 1);
    } else if(ctrl == 3) {
        int click_row = arr[0], click_col = arr[1];
        Chessboard::clickPos(click_row, click_col);
    } else if(ctrl == 4) {
        win->actionAdmitDefeat();
    } else if(ctrl == 5) {
        // this->timeOut();
    } else {
        check(0);
    }
}

void Netboard::netGameInit()
{
    ;
}

void Netboard::syncBoard(QByteArray arr, int part)
{
    const int Half_Size = sizeof(this->p) / 2;
    memcpy(this->p + part * (Half_Size)
           , arr.constData(), Half_Size);

    if(part == 1) {
        this->displayAll();
    }
}
