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
    static Chessboard *board;

    int id;
    int color;
    int row, col;
    bool known, dead;
    Type type;

    void initPiece(int _id, int _team, Type _type);

    virtual void hide() = 0;
    virtual void display() = 0;
    void flip();
    void kill();
    void move(int _row, int _col);

    bool canMove(int _row, int _col);
    bool isIn4Direction(int _row, int _col);
    bool isIn8Direction(int _row, int _col);

    bool tryAttack(Piece &obj);
    void attack(Piece &obj);
    void dieTogether(Piece &obj);

private:

    bool bfs(int s_row, int s_col, int t_row, int t_col);
};

#endif // PIECE_H
