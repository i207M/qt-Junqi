#include "chessboard.h"

#include <algorithm>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Mdebug.h"

bool Chessboard::Railway[12][5] = {
    0, 0, 0, 0, 0,
    1, 1, 1, 1, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 2, 1, 2, 1,
    1, 2, 1, 2, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 0, 0, 0, 1,
    1, 1, 1, 1, 1,
    0, 0, 0, 0, 0
}; //TODO

Chessboard::Chessboard(MainWindow *_win): win(_win)
{
    current_player = 0;
    current_color = 0;
    select_id = -1;

    is_online = false;
    is_server = false;

    timer = nullptr;
    current_time = nullptr;

    Piece::board = this;
    ClickableLabel::board = this;

    initBoard();
}

Chessboard::~Chessboard()
{
    ;
}

void Chessboard::initBoard()
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

    srand(time(0));
    std::random_shuffle(p, p + 50);

    cnt = 0;
    for(int i_type = 0; i_type < 12; ++i_type) {
        for(int i_count = 0; i_count < Initial_Count[i_type]; ++i_count) {
            p[cnt].initPiece(cnt, 1, Type(i_type));
            ++cnt;
        }
    }
    for(int i_type = 0; i_type < 12; ++i_type) {
        for(int i_count = 0; i_count < Initial_Count[i_type]; ++i_count) {
            p[cnt].initPiece(cnt, 2, Type(i_type));
            ++cnt;
        }
    }
}

void Chessboard::displayAll()
{
    for(int i = 0; i < 50; ++i) {
        p[i].display();
    }
}

void Chessboard::nextTurn()
{
    select_id = -1;
}

void Chessboard::clickPos(int row, int col)
{
    err("Click", row, col);
    for(int i = 0; i < 50; ++i) {
        if(p[i].row == row and p[i].col == col) {
            clickPiece(i);
            return;
        }
    }

    // piece not found
    if(select_id != -1 and p[select_id].canMove(row, col)) {
        p[select_id].move(row, col);
        nextTurn();
    } else {
        select_id = -1;
    }
}

void Chessboard::clickPiece(int id)
{
    if(select_id == -1) {
        if(p[id].known == false) {
            p[id].flip();
            if(current_color == 0) {
                static int flip_color[2];
                if(flip_color[current_player - 1] == p[id].color) {
                    current_color = p[id].color;
                    err("Color fixed", current_player, current_color);
                }
                flip_color[current_player - 1] = p[id].color;
            }
        } else if(current_color == p[id].color) {
            select_id = id;
        }
    } else {
        if(current_color == p[id].color) {
            select_id = id;
        } else if(p[select_id].tryAttack(p[id])) {
            nextTurn();
        }
    }
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

bool Chessboard::isRailway(int row, int col)
{
    return Railway[row][col];
}

bool Chessboard::isEmpty(int row, int col)
{
    for(int i = 0; i < 50; ++i) {
        if(not p[i].dead and p[i].row == row and p[i].col == col) {
            return false;
        }
    }
    return true;
}

bool Chessboard::canAttackJunQi()
{
    for(int i = 0; i < 50; ++i) {
        if(p[i].color != current_color and p[i].type == Type::DiLei and not p[i].dead) {
            return false;
        }
    }
    return true;
}

int Chessboard::getNumTurn()
{
    return num_turn;
}
