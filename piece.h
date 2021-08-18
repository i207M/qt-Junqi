#ifndef PIECE_H
#define PIECE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

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

class Piece
{
public:
    static Ui::MainWindow *ui;
    int team;
    bool known, dead;
    Type type;
    Pos pos;

    Piece() {};
    Piece(int _team, Type _type): team(_team), type(_type), known(false), dead(false) {}

    void display();
    void flip();
    void select();
    void kill();

    void tryAttack(Piece &obj);
    bool canAttack();
};

#endif // PIECE_H
