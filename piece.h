#ifndef PIECE_H
#define PIECE_H

struct Pos {
    int row, col;
    Pos() {};
    Pos(int _row, int _col) :  row(_row), col(_col) {}
};

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
    DiLei = 9,
    JunQi = 10
};

struct Piece {
    int team;
    Type type;
    bool known, dead;
    Pos pos;

    Piece() {};
    Piece(int _team, Type _type): team(_team), type(_type), known(false), dead(false) {}
};

#endif // PIECE_H
