#include "chessboard.h"

Chessboard::Chessboard()
{
    win = nullptr;
}

void Chessboard::setMainWindow(MainWindow *_win)
{
    win = _win;
}
