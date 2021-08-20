#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piecedisplay.h"

class MainWindow;

class Chessboard: public QObject
{
    Q_OBJECT

public:
    Chessboard();
    // Chessboard(QObject *parent = nullptr);
    explicit Chessboard(MainWindow *_win);

    void initBoard();
    void displayAll();
    void nextTurn();
    void timeOut();
    void tryAdmitDefeat();
    void tryGameOver();
    virtual void clickPos(int row, int col);
    void clickPiece(int id);

    int getOpp() const;
    int getIdByPos(int row, int col) const;

    static bool isCamp(int row, int col);
    static bool isRailway(int row, int col);
    bool isEmpty(int row, int col) const;
    bool canAttackJunQi() const;
    bool showSelected(int id) const;

    void debugRandomlyKill();

    static bool Railway[12][5];

    PieceDisplay p[50];
    bool is_online;
    int current_player;  // server: 1, client: 2
    int current_color; // red: 1, blue: 2
    int select_id;

protected:
    MainWindow *win;

private:
    void tryDetermineColor(int id);
    void select(int id);

    int num_turn;
    int num_time_out[2];
    int flip_color[2];
};

#endif // CHESSBOARD_H
