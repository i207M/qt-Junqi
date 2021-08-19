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
    static void init(Chessboard *_board);

    int team;
    int row, col;
    bool known, dead, selected;
    Type type;

    void initPiece(int _team, Type _type);

    virtual void hide() = 0;
    virtual void display() = 0;
    void flip();
    void select(bool flag);
    void kill();
    void move(int _row, int _col);

    bool canMove(int row, int col);

    bool tryAttack(Piece &obj);
};

#endif // PIECE_H
