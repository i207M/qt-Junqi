#include "chessboard.h"

#include <algorithm>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "m_debug.h"

int Chessboard::Railway[12][5] = {
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
};

Chessboard::Chessboard(MainWindow *_win): QObject(_win), win(_win)
{
    has_start = false;  // WARNING
    is_online = false;
    current_player = 0;
    current_color = 0;
    select_id = -1;

    num_turn = 0;
    num_time_out[0] = 0, num_time_out[1] = 0;
    flip_color[0] = 0, flip_color[1] = 0;

    timer = new QTimer(this);
    timeRemaining = 0;

    Piece::board = this;
    ClickableLabel::board = this;
}

// Chessboard::~Chessboard()
// {
//     delete timer;
// }

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

    int seed = time(0);
    err("Seed", seed);
    srand(seed);
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
    err("nextTurn");
    ++num_turn;
    endTimer();

    current_player = getOpp();
    if(current_color != 0) {
        current_color = (current_color == 1 ? 2 : 1);
    }
    select(-1);

    if(not is_online) {
        win->changeYouPlayer(current_player, current_color);
    }
    win->changeWhoseTurn(current_player);

    tryGameOver();

    startTimer();
    win->log(QString("Round #%1").arg(num_turn));
    err("__nextTurn");
}

void Chessboard::localPressStart()
{
    initBoard();
    displayAll();

    current_player = 2;  // WARNING
    has_start = true;
    nextTurn();
}

void Chessboard::timeOut()
{
    const int Time_Out_Limit = 3;
    int t = ++num_time_out[current_player - 1];
    if(t >= Time_Out_Limit) {
        win->gameOver(QString("Time out!\nThe Winner is Player %1.").arg(getOpp()));
    } else {
        win->log(QString("Player %1 timed out.").arg(current_player));
    }
    nextTurn();
}

void Chessboard::tryAdmitDefeat()
{
    const int Admit_Defeat_Limit = 20;

    if(num_turn >= Admit_Defeat_Limit) {
        win->gameOver(QString("Admit defeat!\nThe Winner is Player %1.").arg(getOpp()));
    } else {
        win->log("Failed to Admit Defeat. The number of rounds is less than 20.");
    }
}

void Chessboard::tryGameOver()
{
    err("tryGameOver");
    // if(current_color == 0) {
    //     return;
    // }

    for(int i = 0; i < 50; ++i) {
        if(p[i].color == current_color and p[i].type == Type::JunQi and p[i].dead) {
            win->gameOver(QString("Flag Lost!\nThe Winner is Player %1.").arg(getOpp()));
            return;
        }
    }

    for(int i = 0; i < 50; ++i) {
        if(p[i].color == current_color and not p[i].dead and p[i].canMoveAround()) {
            err("possibleMove", p[i].row, p[i].col);
            return;
        }
        if(not p[i].dead and p[i].known == false) {
            return;
        }
    }
    win->gameOver(QString("No Possible Move Found!\nThe Winner is Player %1.").arg(getOpp()));
}

void Chessboard::clickPos(int row, int col)
{
    if(not has_start) {
        return;
    }

    int id = getIdByPos(row, col);
    err("ClickPos", row, col, id);
    check((row >= 0 and row < 12 and col >= 0 and col < 5)
          or (row == -1 and col == -1));
    if(id != -1) {
        clickPiece(id);
        return;
    }

    // piece not found
    if(select_id != -1 and p[select_id].canMove(row, col)) {
        p[select_id].move(row, col);
        nextTurn();
    } else {
        select(-1);
    }
}

void Chessboard::clickPiece(int id)
{
    err("clickPiece", p[id].row, p[id].col);
    if(p[id].known == false) {
        p[id].flip();
        if(current_color == 0) {
            tryDetermineColor(id);
        }
        nextTurn();
    } else if(current_color == p[id].color) {
        select(id);
    } else if(select_id != -1) {
        if(p[select_id].tryAttack(p[id])) {
            nextTurn();
        }
    }
    err("__clickPiece");
}

int Chessboard::getOpp() const
{
    return current_player == 1 ? 2 : 1;
}

int Chessboard::getOpp(int _current_player)
{
    return _current_player == 1 ? 2 : 1;
}

int Chessboard::getIdByPos(int row, int col) const
{
    for(int i = 0; i < 50; ++i) {
        if(p[i].row == row and p[i].col == col and not p[i].dead) {
            return i;
        }
    }
    return -1;
}

bool Chessboard::isCamp(int row, int col)
{
    // static const int Camp_Row[] = {2, 2, 3, 4, 4, 7, 7, 8, 9, 9};
    // static const int Camp_Col[] = {1, 3, 2, 1, 3, 1, 3, 2, 1, 3};
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
    return bool(Railway[row][col]);
}

bool Chessboard::isEmpty(int row, int col) const
{
    for(int i = 0; i < 50; ++i) {
        if(p[i].row == row and p[i].col == col and not p[i].dead) {
            return false;
        }
    }
    return true;
}

bool Chessboard::canAttackJunQi() const
{
    for(int i = 0; i < 50; ++i) {
        if(p[i].color != current_color and p[i].type == Type::DiLei and not p[i].dead) {
            return false;
        }
    }
    return true;
}

bool Chessboard::showSelected(int id) const
{
    if(id == select_id) {
        check(not is_online);
        return true;
    } else {
        return false;
    }
}

void Chessboard::tryDetermineColor(int id)
{
    if(flip_color[current_player - 1] == p[id].color) {
        current_color = p[id].color;
        win->log(QString("Color determined: Player %1 is %2").arg(current_player)
                 .arg(current_color == 1 ? "red" : "blue"));
    }
    flip_color[current_player - 1] = p[id].color;
}

void Chessboard::select(int id)
{
    if(id == -1) {
        if(select_id != -1) {
            int t = select_id;
            select_id = -1;
            p[t].display();
        }
    } else if(select_id == -1) {
        select_id = id;
        p[id].display();
    } else {
        int t = select_id;
        select_id = id;
        p[t].display();
        p[id].display();
    }
}

void Chessboard::startTimer()
{
    const int Player_Time = 20;

    timeRemaining = Player_Time;
    win->ui->lcdNumber->display(timeRemaining);

    newOneSecond();
}

void Chessboard::endTimer()
{
    timer->stop();
}

void Chessboard::newOneSecond()
{
    delete timer;
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &Chessboard::oneSecond);
    timer->start(1000);
}

void Chessboard::oneSecond()
{
    --timeRemaining;
    win->ui->lcdNumber->display(timeRemaining);

    if(timeRemaining <= 0) {
        timeOut();
    } else {
        newOneSecond();
    }
}

void Chessboard::debugRandomlyKill()
{
    for(int i = 0; i < 50; ++i) {
        if(p[i].type != Type::JunQi and not p[i].dead and rand() % 2 == 1) {
            p[i].kill();
        }
    }
}
