#include "chessboard.h"

Chessboard::Chessboard()
{
    win = nullptr;
}

Chessboard::~Chessboard()
{
    ;
}

void Chessboard::setMainWindow(MainWindow *_win)
{
    win = _win;
}
