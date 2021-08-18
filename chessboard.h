#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <cstdlib>
#include <ctime>
#include <algorithm>

#include <QPainter>
#include <QTime>
#include <QTimer>

#include "piece.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE
class MainWindow;

class Chessboard
{
public:
    Chessboard() = delete;
    ~Chessboard();
    explicit Chessboard(MainWindow *_win);
    void init();
    void display();
    void clicked();
    void nextTurn();

    void flipPiece(int id);
    void selectPiece(int id);
    void deletePiece(int id);
    void clickPiece(int id);

    void tryAttack(int id, int object);
    bool canAttack();
    bool canWinAttack();

    void tryAdmitDefeat();
    bool canAdmitDefeat();

    int getIdByPos();

    int canGameOver();
    void gameOver(const char *display_str);
private:
    MainWindow *win;

    int player_id;
    int select_id;
    Piece p[60];

    QTimer *timer;
    QTime *current_time;
};

#endif // CHESSBOARD_H
