#include "piece.h"

#include <algorithm>
#include <vector>
#include <queue>
using std::min;
using std::max;
using std::pair;
using std::make_pair;
using std::queue;
using std::vector;

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
    err("Flip", row, col);
    known = true;
    display();
}

void Piece::kill()
{
    err("Kill", row, col);
    dead = true;
    display();
}

void Piece::move(int _row, int _col)
{
    hide();
    err("Move", row, col, _row, _col);
    row = _row, col = _col;
    display();
}

bool Piece::canMove(int _row, int _col)
{
    // assert that when trying to move, the destination is empty
    //             when trying to attack, the destination is not, so don't check

    check(row != _row or col != _col);

    if(int(type) >= 10) {
        return false;
    } else if(isIn4Direction(_row, _col)) {
        // special case: (5, 1), (5, 3)
        int min_row = min(row, _row);
        int max_row = max(row, _row);
        if((min_row == 5 and col == 1 and max_row == 6 and _col == 1)
                or (min_row == 5 and col == 3 and max_row == 6 and _col == 3)) {
            return false;
        }
        return true;
    } else if( (board->isCamp(row, col) or board->isCamp(_row, _col))
               and isIn8Direction(_row, _col)) {
        return true;
    } else if(board->isRailway(row, col) and board->isRailway(_row, _col)) {
        if(type == Type::GongBing) {
            return bfs(row, col, _row, _col);
        } else {
            if(row == _row) {
                return goVerticalRailway(row, col, _col);
            } else if(col == _col) {
                return goHorizontalRailway(col, row, _row);
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

bool Piece::goVerticalRailway(int row, int col, int _col)
{
    int st = min(col, _col), ed = max(col, _col);
    for(int i = st + 1; i < ed; ++i) {
        if(not (board->isRailway(row, i) and board->isEmpty(row, i))) {
            return false;
        }
    }
    return true;
}

bool Piece::goHorizontalRailway(int col, int row, int _row)
{
    int st = min(row, _row), ed = max(row, _row);
    for(int i = st + 1; i < ed; ++i) {
        if(not (board->isRailway(i, col) and board->isEmpty(i, col))) {
            return false;
        }
    }
    return true;
}

bool Piece::tryAttack(Piece &obj)
{
    check(id != obj.id);
    if(canMove(obj.row, obj.col) and not board->isCamp(obj.row, obj.col)) {
        if(obj.type == Type::DiLei) {
            if(type == Type::GongBing) {
                attack(obj);
                return true;
            } else if(type == Type::ZhaDan) {
                dieTogether(obj);
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
    static bool vis[12][5];
    memset(vis, 0, sizeof(vis));
    queue< pair<int, int> > q;

    q.push(make_pair(s_row, s_col));
    vis[s_row][s_col] = true;

    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();

        static const vector<int> r4 = {-1, 0, 1, 0};
        static const vector<int> c4 = {0, 1, 0, -1};
        static const vector<int> r2 = {0, 0};
        static const vector<int> c2 = {1, -1};
        vector<int> r, c;
        check(Chessboard::Railway[row][col]);
        if(Chessboard::Railway[row][col] == 1) {
            r = r4, c = c4;
        } else {
            r = r2, c = c2;
        }

        for(int i = 0; i < r.size(); ++i) {
            int n_row = row + r[i], n_col = col + c[i];

            if(n_row == t_row and n_col == t_col) {
                return true;
            }

            if(n_row >= 0 and n_row < 12 and n_col >= 0 and n_col <= 5
                    and Chessboard::Railway[n_row][n_col]
                    and board->isEmpty(n_row, n_col)
                    and not vis[n_row][n_col]) {
                q.push(make_pair(n_row, n_col));
                vis[n_row][n_col] = true;
            }
        }
    }
    return false;
}
