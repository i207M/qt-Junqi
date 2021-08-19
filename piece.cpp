#include "piece.h"

#include <algorithm>
using std::min;
using std::max;

#include "chessboard.h"
#include "Mdebug.h"

Chessboard *Piece::board = nullptr;

void Piece::initPiece(int _id, int _team, Type _type)
{
    id = _id, color = _team, type = _type;
    known = false, dead = false;
}

void Piece::flip()
{
    known = true;
}

void Piece::kill()
{
    dead = true;
}

void Piece::move(int _row, int _col)
{
    row = _row, col = _col;
}

bool Piece::canMove(int _row, int _col)
{
    if(int(type) >= 10) {
        return false;
    } else if(isIn4Direction(_row, _col)) {
        return true;
    } else if(board->isCamp(_row, _col) and isIn8Direction(_row, _col)) {
        return true;
    } else if(board->isRailway(row, col) and board->isRailway(_row, _col)) {
        if(type == Type::GongBing) {
            return bfs(row, col, _row, _col);
        } else {
            if(row == _row) {
                int st = min(col, _col), ed = max(col, _col);
                for(int i = st; i <= ed; ++i) {
                    if(not (board->isRailway(row, i) and board->isEmpty(row, i))) {
                        return false;
                    }
                }
                return true;
            } else if(col == _col) {
                int st = min(row, _row), ed = max(row, _row);
                for(int i = st; i <= ed; ++i) {
                    if(not (board->isRailway(i, col) and board->isEmpty(i, col))) {
                        return false;
                    }
                }
                return true;
            }
        }
    }
    return false;
}

bool Piece::isIn4Direction(int _row, int _col)
{
    static const int r[] = {-1, 0, 1, 0};
    static const int c[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; ++i) {
        if(row + r[i] == _row and col + c[i] == _col) {
            return true;
        }
    }
    return false;
}

bool Piece::isIn8Direction(int _row, int _col)
{
    static const int r[] = {-1, 1, 1, -1};
    static const int c[] = {1, 1, -1, -1};
    for(int i = 0; i < 4; ++i) {
        if(row + r[i] == _row and col + c[i] == _col) {
            return true;
        }
    }
    return false;
}

bool Piece::tryAttack(Piece &obj)
{
    if(canMove(obj.row, obj.col)) {
        if(obj.type == Type::DiLei) {
            if(type == Type::GongBing) {
                attack(obj);
                return true;
            }
        } else if(obj.type == Type::JunQi) {
            if(board->canAttackJunQi()) {
                attack(obj);
                return true;
            }
        } else if(type == Type::ZhaDan or obj.type == Type::ZhaDan) {
            dieTogether(obj);
            return true;
        } else if(type == obj.type) {
            dieTogether(obj);
            return true;
        } else if(type > obj.type) {
            attack(obj);
            return true;
        }
    }
    return false;
}

void Piece::attack(Piece &obj)
{
    obj.kill();
    move(obj.row, obj.col);
}

void Piece::dieTogether(Piece &obj)
{
    obj.kill();
    kill();
}

bool Piece::bfs(int s_row, int s_col, int t_row, int t_col)
{
    ;
}
