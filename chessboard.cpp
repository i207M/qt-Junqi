#include "chessboard.h"
#include "mainwindow.h"

Chessboard::Chessboard() {}

Chessboard::~Chessboard()
{
    ;
}

void Chessboard::setMainWindow(MainWindow *_win)
{
    win = _win;
    ui = _win->getUi();
}

void Chessboard::init()
{
    const static int InitialCount[] = {3, 3, 3, 2, 2, 2, 2, 1, 1, 3, 1};

    int cnt = 0;
    for(int i_type = 0; i_type < 11; ++i_type) {
        for(int i_count = 0; i_count < InitialCount[i_type]; ++i_count) {
            p[cnt] = Piece(1, Type(i_type));
            ++cnt;
        }
    }
    for(int i_type = 0; i_type < 11; ++i_type) {
        for(int i_count = 0; i_count < InitialCount[i_type]; ++i_count) {
            p[cnt] = Piece(2, Type(i_type));
            ++cnt;
        }
    }

    static Pos _pos[60];
    cnt = 0;

    for(int i = 0; i < 12; ++i) {
        for (int j = 0; j < 5; ++j) {
            _pos[cnt] = Pos(i, j);
            ++cnt;
        }
    }

    srand(time(0));
    std::random_shuffle(_pos, _pos + 60);

    for (int i = 0; i < 60; ++i) {
        p[i].pos = _pos[i];
    }
}

void Chessboard::paintEvent(QPaintEvent *)
{
    QPainter painter(win);
    painter.drawLine(QPoint(10, 10), QPoint(10, 20));
}
