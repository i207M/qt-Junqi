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
    check(not known);
    known = true;
    display();
}

void Piece::kill()
{
    err("Kill", row, col);
    check(not dead);
    dead = true;
    display();
}

void Piece::move(int _row, int _col)
{
    err("Move", row, col, _row, _col);
    check(not dead);
    hide();
    row = _row, col = _col;
    display();
}

bool Piece::goVerticalRailway(int row, int col, int n_col)
{
    int st = min(col, n_col), ed = max(col, n_col);
    for(int i = st + 1; i < ed; ++i) {
        if(not (board->isRailway(row, i) and board->isEmpty(row, i))) {
            return false;
        }
    }
    return true;
}

bool Piece::goHorizontalRailway(int col, int row, int n_row)
{
    int st = min(row, n_row), ed = max(row, n_row);
    for(int i = st + 1; i < ed; ++i) {
        if(not (board->isRailway(i, col) and board->isEmpty(i, col))) {
            return false;
        }
    }
    return true;
}

bool Piece::canMove(int n_row, int n_col) const
{
    // assert that when trying to move, the destination is empty
    //             when trying to attack, the destination is not, so don't check
    err("canMove", row, col, n_row, n_col);
    check(row != n_row or col != n_col);

    if(int(type) >= 10) {
        return false;
    } else if(isIn4Direction(n_row, n_col)) {
        // special case: (5, 1), (5, 3)
        int min_row = min(row, n_row);
        int max_row = max(row, n_row);
        if((min_row == 5 and col == 1 and max_row == 6 and n_col == 1)
                or (min_row == 5 and col == 3 and max_row == 6 and n_col == 3)) {
            return false;
        }
        return true;
    } else if((Chessboard::isCamp(row, col) or Chessboard::isCamp(n_row, n_col))
              and isIn8Direction(n_row, n_col)) {
        return true;
    } else if(Chessboard::isRailway(row, col) and Chessboard::isRailway(n_row, n_col)) {
        if(type == Type::GongBing) {
            return bfs(row, col, n_row, n_col);
        } else {
            if(row == n_row) {
                return goVerticalRailway(row, col, n_col);
            } else if(col == n_col) {
                return goHorizontalRailway(col, row, n_row);
            }
        }
    }
    return false;
}

bool Piece::canMoveAround()
{
    if(int(type) >= 10) {
        return false;
    } else {
        static const int r[] = {-1, 0, 1, 0, -1, 1, 1, -1};
        static const int c[] = {0, 1, 0, -1, 1, 1, -1, -1};
        for(int i = 0; i < 8; ++i) {
            int n_row = row + r[i], n_col = col + c[i];
            if(n_row >= 0 and n_row < 12 and n_col >= 0 and n_col <= 5) {
                int n_id = board->getIdByPos(n_row, n_col);
                if(n_id == -1) {
                    if(canMove(n_row, n_col)) {
                        return true;
                    }
                } else if(canAttack(board->p[n_id])) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool Piece::isIn4Direction(int n_row, int n_col) const
{
    static const int r[] = {-1, 0, 1, 0};
    static const int c[] = {0, 1, 0, -1};
    for(int i = 0; i < 4; ++i) {
        if(row + r[i] == n_row and col + c[i] == n_col) {
            return true;
        }
    }
    return false;
}

bool Piece::isIn8Direction(int n_row, int n_col) const
{
    static const int r[] = {-1, 1, 1, -1};
    static const int c[] = {1, 1, -1, -1};
    for(int i = 0; i < 4; ++i) {
        if(row + r[i] == n_row and col + c[i] == n_col) {
            return true;
        }
    }
    return false;
}

bool Piece::canAttack(const Piece &obj) const
{
    if(color == obj.color) {
        return false;
    }

    if(canMove(obj.row, obj.col) and not Chessboard::isCamp(obj.row, obj.col)) {
        if(obj.type == Type::DiLei) {
            if(type == Type::GongBing or type == Type::ZhaDan) {
                return true;
            }
        } else if(obj.type == Type::JunQi) {
            if(board->canAttackJunQi()) {
                return true;
            }
        } else if(type == Type::ZhaDan or obj.type == Type::ZhaDan) {
            return true;
        } else if(type >= obj.type) {
            return true;
        }
    }

    return false;
}

bool Piece::tryAttack(Piece &obj)
{
    err("tryAttack", row, col, obj.row, obj.col);
    check(color != obj.color);

    if(canMove(obj.row, obj.col) and not Chessboard::isCamp(obj.row, obj.col)) {
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
                if(type == Type::ZhaDan) {
                    dieTogether(obj);
                } else {
                    attack(obj);
                }
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

bool Piece::bfs(int s_row, int s_col, int t_row, int t_col) const
{
    static bool vis[12][5];
    memset(vis, 0, sizeof(vis));
    queue< pair<int, int> > q;

    q.push(make_pair(s_row, s_col));
    vis[s_row][s_col] = true;

    while(!q.empty()) {
        int row = q.front().first, col = q.front().second;
        q.pop();
        check(Chessboard::Railway[row][col]);

        static const vector<int> r4 = {-1, 0, 1, 0};
        static const vector<int> c4 = {0, 1, 0, -1};
        static const vector<int> r2 = {0, 0};
        static const vector<int> c2 = {1, -1};
        vector<int> r, c;
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
