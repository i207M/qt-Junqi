#ifndef NETBOARD_H
#define NETBOARD_H

#include <QNetworkInterface>

#include "chessboard.h"

class Netboard : public Chessboard
{
public:
    Netboard() = delete;
    explicit Netboard(MainWindow *_win, QHostAddress ip);
};

#endif // NETBOARD_H
