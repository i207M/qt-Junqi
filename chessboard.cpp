#include <algorithm>

#include <QMainWindow>
#include <QLabel>

#include "chessboard.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

QLabel *Piece::label_map[12][5] = {};
Chessboard::Chessboard(MainWindow *_win)
{
    win = _win;

    player_id = 1;
    select_id = -1;

    init();
    Piece::label_map[0][0] = win->ui->label_1;
    Piece::label_map[0][1] = win->ui->label_2;
    Piece::label_map[0][2] = win->ui->label_3;
    Piece::label_map[0][3] = win->ui->label_4;
    Piece::label_map[0][4] = win->ui->label_5;
    Piece::label_map[1][0] = win->ui->label_6;
    Piece::label_map[1][1] = win->ui->label_7;
    Piece::label_map[1][2] = win->ui->label_8;
    Piece::label_map[1][3] = win->ui->label_9;
    Piece::label_map[1][4] = win->ui->label_10;
    Piece::label_map[2][0] = win->ui->label_11;
    Piece::label_map[2][1] = win->ui->label_12;
    Piece::label_map[2][2] = win->ui->label_13;
    Piece::label_map[2][3] = win->ui->label_14;
    Piece::label_map[2][4] = win->ui->label_15;
    Piece::label_map[3][0] = win->ui->label_16;
    Piece::label_map[3][1] = win->ui->label_17;
    Piece::label_map[3][2] = win->ui->label_18;
    Piece::label_map[3][3] = win->ui->label_19;
    Piece::label_map[3][4] = win->ui->label_20;
    Piece::label_map[4][0] = win->ui->label_21;
    Piece::label_map[4][1] = win->ui->label_22;
    Piece::label_map[4][2] = win->ui->label_23;
    Piece::label_map[4][3] = win->ui->label_24;
    Piece::label_map[4][4] = win->ui->label_25;
    Piece::label_map[5][0] = win->ui->label_26;
    Piece::label_map[5][1] = win->ui->label_27;
    Piece::label_map[5][2] = win->ui->label_28;
    Piece::label_map[5][3] = win->ui->label_29;
    Piece::label_map[5][4] = win->ui->label_30;
    Piece::label_map[6][0] = win->ui->label_31;
    Piece::label_map[6][1] = win->ui->label_32;
    Piece::label_map[6][2] = win->ui->label_33;
    Piece::label_map[6][3] = win->ui->label_34;
    Piece::label_map[6][4] = win->ui->label_35;
    Piece::label_map[7][0] = win->ui->label_36;
    Piece::label_map[7][1] = win->ui->label_37;
    Piece::label_map[7][2] = win->ui->label_38;
    Piece::label_map[7][3] = win->ui->label_39;
    Piece::label_map[7][4] = win->ui->label_40;
    Piece::label_map[8][0] = win->ui->label_41;
    Piece::label_map[8][1] = win->ui->label_42;
    Piece::label_map[8][2] = win->ui->label_43;
    Piece::label_map[8][3] = win->ui->label_44;
    Piece::label_map[8][4] = win->ui->label_45;
    Piece::label_map[9][0] = win->ui->label_46;
    Piece::label_map[9][1] = win->ui->label_47;
    Piece::label_map[9][2] = win->ui->label_48;
    Piece::label_map[9][3] = win->ui->label_49;
    Piece::label_map[9][4] = win->ui->label_50;
    Piece::label_map[10][0] = win->ui->label_51;
    Piece::label_map[10][1] = win->ui->label_52;
    Piece::label_map[10][2] = win->ui->label_53;
    Piece::label_map[10][3] = win->ui->label_54;
    Piece::label_map[10][4] = win->ui->label_55;
    Piece::label_map[11][0] = win->ui->label_56;
    Piece::label_map[11][1] = win->ui->label_57;
    Piece::label_map[11][2] = win->ui->label_58;
    Piece::label_map[11][3] = win->ui->label_59;
    Piece::label_map[11][4] = win->ui->label_60;
}

Chessboard::~Chessboard()
{
    ;
}

void Chessboard::init()
{
    const static int InitialCount[] = {3, 3, 3, 2, 2, 2, 2, 1, 1, 3, 1};

    int cnt = 0;
    for(int i = 0; i < 12; ++i) {
        for (int j = 0; j < 5; ++j) {
            p[cnt].row = i, p[cnt].col = j;
            ++cnt;
        }
    }

    srand(time(0));
    std::random_shuffle(p, p + 60);

    cnt = 0;
    for(int i_type = 0; i_type < 11; ++i_type) {
        for(int i_count = 0; i_count < InitialCount[i_type]; ++i_count) {
            p[cnt].init(1, Type(i_type));
            ++cnt;
        }
    }
    for(int i_type = 0; i_type < 11; ++i_type) {
        for(int i_count = 0; i_count < InitialCount[i_type]; ++i_count) {
            p[cnt].init(2, Type(i_type));
            ++cnt;
        }
    }
}

void Chessboard::display()
{
    for(int i = 0; i < 60; ++i) {
        p[i].display();
    }
}

void Chessboard::tryAdmitDefeat()
{
    ;
}
