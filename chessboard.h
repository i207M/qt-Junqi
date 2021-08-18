#ifndef CHESSBOARD_H
#define CHESSBOARD_H

struct Pos {
    int row, col;
    Pos();
    ~Pos();
    Pos(int _row, int _col)
    {
        row = _row, col = _col;
    }
};

struct Piece {
    int team, type, num;
    bool known, dead;
    Pos pos;
};

class MainWindow;

class Chessboard
{
public:
    Chessboard();
    ~Chessboard();
    void setMainWindow(MainWindow *_win);
    void clicked();
    void nextTurn();
    int canGameOver();
    void gameOver(bool win);

    void display();
    void displayPiece(int id, Pos pos, bool known);
    void flipPiece(int id);
    void selectPiece(int id);
    void deletePiece(int id);
    void move(int id, Pos pre, Pos nxt);
    void tryAttack(int id, int object);

    bool canAttack();
    bool canWinAttack();

    int getIdByPos();
private:
    MainWindow *win;

    int player_id;
};

#endif // CHESSBOARD_H
