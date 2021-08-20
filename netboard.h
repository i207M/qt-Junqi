#ifndef NETBOARD_H
#define NETBOARD_H

#include <QNetworkInterface>
#include <QTcpServer>
#include <QTcpSocket>

#include "chessboard.h"

class Netboard : public Chessboard
{
    Q_OBJECT

public:
    // explicit Netboard(QObject *parent = nullptr);
    explicit Netboard(MainWindow *_win, QString ip);

    virtual void clickPos(int row, int col) override;

public slots:
    void slotNewConnection();
    void slotRecv();

private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    int local_player;  // 1: server, 2: client
};

#endif // NETBOARD_H