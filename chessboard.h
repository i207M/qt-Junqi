#ifndef CHESSBOARD_H
#define CHESSBOARD_H

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
    void timeOut();
    void tryAdmitDefeat();

    int getIdByPos(int row,int col);
    void clickPos(int row, int col);
    void clickPiece(int id);
    void select(int id);

    bool isCamp(int row, int col);
    bool isRailway(int row, int col);
    bool isEmpty(int row, int col);
    bool canAttackJunQi();
    bool showSelected(int id);

    int getNumTurn();

    void tryGameOver();

    int current_player;  // server: 1, client: 2
    int current_color; // red: 1, blue: 2
    int select_id;

    bool is_online;

    static bool Railway[12][5];
    PieceDisplay p[50];

private:
    void tryDetermineColor(int id);
    MainWindow *win;

    int num_turn;

    int num_time_out[2];
};

#endif // CHESSBOARD_H
