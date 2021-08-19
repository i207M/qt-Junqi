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

class Piece
{
public:
    int team;
    int row, col;
    bool known, dead, selected;
    Type type;

    void init(int _team, Type _type);

    virtual void hide() = 0;
    virtual void display() = 0;
    void flip();
    void select();
    void kill();
    void move();

    void tryAttack(Piece &obj);
    bool canAttack();
};

#endif // PIECE_H
