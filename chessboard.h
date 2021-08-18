#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QTime>
#include <QTimer>

#include "piece.h"

class MainWindow;

class Chessboard
{
public:
    Chessboard() = delete;
    ~Chessboard();
    explicit Chessboard(MainWindow *_win);
    void init();
    void display();

    void clickPos(Pos pos);
    void clickPiece(int id);

    void nextTurn();

    void tryAdmitDefeat();
    bool canAdmitDefeat();

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
