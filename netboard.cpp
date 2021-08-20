#include "netboard.h"

#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Mdebug.h"

Netboard::Netboard(MainWindow *_win, QString ip): Chessboard(_win)
{
    const int PORT = 2077;

    qDebug() << "Netboard init " << ip;
    check(ip != "-1");

    this->is_online = true;
    random_prior[0] = -1, random_prior[1] = -1;

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

void Netboard::slotNewConnection()
{
    err("Got connection");
    if(tcpSocket != nullptr) {
        err("Reject multiple connection");
        return;
    }

    tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::readyRead, this, &Netboard::slotRecv);

    win->connectSuccessfully();

    netGameInit();

    static const char Ctrl0[1] = {0};
    tcpSocket->write(Ctrl0, 1);
}

void Netboard::slotRecv()
{
    QByteArray arr = tcpSocket->readAll();
    char ctrl = arr[0];
    err("Recv Ctrl", ctrl);

    if(ctrl == 0) {
        check(local_player == 2);
        win->connectSuccessfully();
    } else if(ctrl == 1) {
        syncBoard(arr);
    } else if(ctrl == 2) {
        netPressStart(arr[1]);
    } else if(ctrl == 3) {
        // DEPRECATED
        err("Error Deprecated Ctrl");
    } else if(ctrl == 4) {
        int click_row = arr[0], click_col = arr[1];
        Chessboard::clickPos(click_row, click_col);
    } else if(ctrl == 5) {
        // TODO: cannot admit defeat as your opponent
        // win->actionAdmitDefeat();
    } else if(ctrl == 6) {
        err("Opponent timed out.");
    } else {
        err("Error Ctrl");
    }
}

void Netboard::clickPos(int row, int col)
{
    Chessboard::clickPos(row, col);
    char Ctrl4[3] = {4, row, col};
    tcpSocket->write(Ctrl4, 3);
}

void Netboard::localPressStart()
{
    err("localPressStart");
    if(tcpSocket == nullptr) {
        QMessageBox::warning(this->win,
                             tr("Warning"),
                             tr("Client Not Connected."));
        return;
    }

    genRandomPrior();

    char Ctrl2[2] = {2, random_prior[0]};
    tcpSocket->write(Ctrl2, 2);

    checkStart();
}

void Netboard::netPressStart(char _random_prior)
{
    random_prior[1] = _random_prior;
    checkStart();
}

void Netboard::netGameInit()
{
    this->initBoard();
    this->displayAll();

    static char chess_data[1 + 50 * 7];
    int cnt = 0;
    chess_data[cnt++] = 1;

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
    int cnt = 1;
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

void Netboard::genRandomPrior()
{
    if(random_prior[0] == -1) {
        srand(time(0));
        random_prior[0] = rand() % 128;
    }
}

void Netboard::checkStart()
{
    if(random_prior[0] == -1 or random_prior[1] == -1) {
        return;
    } else {
        if(random_prior[0] >= random_prior[1]) {
            // self is the first
            // need swap
            this->current_player = this->getOpp(local_player);
        } else {
            // opponent is the first
            // need swap
            this->current_player = local_player;
        }
        this->has_start = true;
        this->nextTurn();
    }
}
