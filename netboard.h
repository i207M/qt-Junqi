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
    explicit Netboard(MainWindow *_win, QString ip);

    virtual void localPressStart() override;
    virtual void netPressStart(char _random_prior);
    virtual void clickPos(int row, int col) override;

private slots:
    void slotNewConnection();
    void slotRecv();

protected:
    virtual void tryDetermineColor(int id) override;

private:
    void sendBoard();
    void syncBoard(QByteArray chessData);
    void genRandomPrior();
    void checkStart();

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    int local_player;  // 1: server, 2: client
    int local_color;
    char random_prior[2]; // 0: self, 1: opponent
};

#endif // NETBOARD_H
