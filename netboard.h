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
    virtual ~Netboard();

    virtual void localPressStart() override;
    void netPressStart(int _random_prior);
    virtual void clickPos(int row, int col) override;
    virtual void timeOut() override;
    virtual void tryAdmitDefeat() override;
    virtual bool showSelected(int id) const override;

    virtual void stopHeartBeat() override;
    virtual void debugRandomlyKill() override;

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

    void initHeartBeat();
    void sendHeartBeat();
    void recvHeartBeat();
    void oppDisconnect();

    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;
    QTimer *send_heart_beat;
    QTimer *recv_heart_beat;
    QTimer *connect_timer;

    int local_player;  // 1: server, 2: client
    int local_color;
    int random_prior[2];  // 0: self, 1: opponent
    int last_heart_beat;
    bool is_connected;
};

#endif // NETBOARD_H
