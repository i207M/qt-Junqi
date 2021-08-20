#include "netboard.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Mdebug.h"

Netboard::Netboard(MainWindow *_win, QHostAddress ip): Chessboard(_win)
{
    win->log(ip.toString());
}
