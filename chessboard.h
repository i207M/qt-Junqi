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

    int current_player;  // server: 1, client: 2
    int current_color; // red: 1, blue: 2
    int select_id;

    bool is_online;
    int is_server;

private:
    MainWindow *win;
    QTimer *timer;
    QTime *current_time;

    PieceDisplay p[50];
    int num_turn;
};

#endif // CHESSBOARD_H
