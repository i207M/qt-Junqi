#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include "piecedisplay.h"

class MainWindow;

class Chessboard: public QObject
{
    Q_OBJECT

public:
    Chessboard() = delete;
    explicit Chessboard(MainWindow *_win);

    // logic
    virtual void localPressStart();
    void initBoard();
    void displayAll();
    void nextTurn();
    void timeOut();
    void tryAdmitDefeat();
    void tryGameOver();
    virtual void clickPos(int row, int col);
    void clickPiece(int id);

    int getOpp() const;
    static int getOpp(int _current_player);
    int getIdByPos(int row, int col) const;

    static bool isCamp(int row, int col);
    static bool isRailway(int row, int col);
    bool isEmpty(int row, int col) const;
    bool canAttackJunQi() const;
    virtual bool showSelected(int id) const;

    // debug
    void debugRandomlyKill();

    static bool Railway[12][5];

    PieceDisplay p[50];

protected:
    virtual void tryDetermineColor(int id);
    void select(int id);

    MainWindow *win;

    bool is_online;
    bool has_start;
    int current_player;  // server: 1, client: 2
    int current_color; // red: 1, blue: 2
    int flip_color[2];
    int num_turn;

private:
    int num_time_out[2];
    int select_id;
};

#endif // CHESSBOARD_H
