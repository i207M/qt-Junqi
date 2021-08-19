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

    void clickPos(int row, int col);
    void clickPiece(int id);
    void selectPiece(int id);
    void unselectPiece();

    bool isCamp(int row, int col);

    void nextTurn();

    int getNumTurn();

    int canGameOver();
    void gameOver(const char *display_str);

private:
    MainWindow *win;

    int P1_color;  // red: 1, blue: 2
    int player_id;
    int select_id;
    int num_turn;

    PieceDisplay p[50];

    QTimer *timer;
    QTime *current_time;
};

#endif // CHESSBOARD_H
