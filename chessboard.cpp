#include "chessboard.h"

#include <algorithm>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Mdebug.h"

Chessboard::Chessboard(MainWindow *_win): win(_win)
{
    player_id = 1;
    select_id = -1;
    P1_color = 0;

    timer = nullptr;
    current_time = nullptr;

    init();
    ClickableLabel::board = this;
}

Chessboard::~Chessboard()
{
    ;
}

void Chessboard::init()
{
    static const int Initial_Count[] = {3, 3, 3, 2, 2, 2, 2, 1, 1, 2, 3, 1};

    int cnt = 0;
    for(int i = 0; i < 12; ++i) {
        for (int j = 0; j < 5; ++j) {
            if(not isCamp(i, j)) {
                p[cnt].row = i, p[cnt].col = j;
                ++cnt;
            }
        }
    }
    assert(cnt == 50);

    srand(time(0));
    std::random_shuffle(p, p + 50);

    cnt = 0;
    for(int i_type = 0; i_type < 12; ++i_type) {
        for(int i_count = 0; i_count < Initial_Count[i_type]; ++i_count) {
            p[cnt].init(1, Type(i_type));
            ++cnt;
        }
    }
    for(int i_type = 0; i_type < 12; ++i_type) {
        for(int i_count = 0; i_count < Initial_Count[i_type]; ++i_count) {
            p[cnt].init(2, Type(i_type));
            ++cnt;
        }
    }
    assert(cnt == 50);
}

void Chessboard::displayAll()
{
    for(int i = 0; i < 50; ++i) {
        p[i].display();
    }
}

void Chessboard::clickPos(int row, int col)
{
    err("click", row, col);
}

bool Chessboard::isCamp(int row, int col)
{
    // static const int Camp_Row[] = {2, 2, 3, 4, 4, 7, 7, 8, 9, 9};
    // static const int Camp_Col[] = {1, 3, 2, 1, 3, 1, 3, 2, 1, 3};
    // for (int i = 0; i < 10; ++i) {
    //     if (row == Camp_Row[i] and col == Camp_Col[i]) {
    //         return true;
    //     }
    // }
    if (col == 1 or col == 3) {
        return row == 2 or row == 4 or row == 7 or row == 9;
    } else if (col == 2) {
        return row == 3 or row == 8;
    } else {
        return false;
    }
}

void Chessboard::tryAdmitDefeat()
{
    ;
}
