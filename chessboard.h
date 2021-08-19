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

    void initBoard();
    void displayAll();
    void nextTurn();

    void clickPos(int row, int col);
    void clickPiece(int id);

    bool isCamp(int row, int col);
    bool canAttackJunQi();

    int getNumTurn();

    int canGameOver();

    int player_id;  // server: 1, client: 2
    int player_color; // red: 1, blue: 2
    int select_id;

private:
    MainWindow *win;
    int num_turn;

    PieceDisplay p[50];

    QTimer *timer;
    QTime *current_time;
};

#endif // CHESSBOARD_H
