#ifndef PIECE_H
#define PIECE_H

enum class Type : int {
    GongBing = 0,
    PaiZhang = 1,
    LianZhang = 2,
    YingZhang = 3,
    TuanZhang = 4,
    LvZhang = 5,
    ShiZhang = 6,
    JunZhang = 7,
    SiLing = 8,
    ZhaDan = 9,
    DiLei = 10,
    JunQi = 11
};

class Chessboard;

class Piece
{
public:
    void initPiece(int _id, int _team, Type _type);
    virtual void hide() = 0;
    virtual void display() = 0;
    void flip();
    void kill();
    void move(int _row, int _col);

    static bool goHorizontalRailway(int row, int col, int n_col);
    static bool goVerticalRailway(int col, int row, int n_row);
    bool canMove(int n_row, int n_col) const;
    bool canMoveAround();
    bool isIn4Direction(int n_row, int n_col) const;
    bool isIn8Direction(int n_row, int n_col) const;
    bool canAttack(const Piece &obj) const;

    bool tryAttack(Piece &obj);
    void attack(Piece &obj);
    void dieTogether(Piece &obj);

    static Chessboard *board;

    int id;
    int color;
    int row, col;
    bool known, dead;
    Type type;

private:
    bool bfs(int s_row, int s_col, int t_row, int t_col) const;
};

#endif // PIECE_H
