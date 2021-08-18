#include "chessboard.h"

Chessboard::Chessboard()
{
    win = nullptr;
}

void Chessboard::setMainWindow(Ui::MainWindow *_win)
{
    win = _win;
}
