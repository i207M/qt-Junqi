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
    void select(int id);

    bool isCamp(int row, int col);
    bool isRailway(int row, int col);
    bool isEmpty(int row, int col);
    bool canAttackJunQi();

    int getNumTurn();

    int canGameOver();

    int current_player;  // server: 1, client: 2
    int current_color; // red: 1, blue: 2
    int select_id;

    bool is_online;
    bool is_server;

    static bool Railway[12][5];

private:
    MainWindow *win;
    QTimer *timer;
    QTime *current_time;

    int num_turn;
    PieceDisplay p[50];
};

#endif // CHESSBOARD_H
