#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QTime>
#include <QTimer>

#include "piecedisplay.h"

class MainWindow;

class Chessboard
{
public:
    Chessboard() = delete;
    ~Chessboard();
    explicit Chessboard(MainWindow *_win);

    void init();
    void displayAll();

    void clickPos(int row, int col);
    void clickPiece(int id);
    void selectPiece(int id);

    bool isCamp(int row, int col);
    bool canMove();

    void nextTurn();

    void tryAdmitDefeat();
    bool canAdmitDefeat();

    int canGameOver();
    void gameOver(const char *display_str);

private:
    MainWindow *win;

    int player_id;
    int select_id;
    PieceDisplay p[50];

    QTimer *timer;
    QTime *current_time;
};

#endif // CHESSBOARD_H
