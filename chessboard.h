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
    int team, type, num, id;
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
    Pos getClickPos();
    void nextTurn();

    void display();
    void displayPiece(int id, Pos pos, bool known);
    void move(int id, Pos pre, Pos nxt);
    void deletePiece(int id);
    void selectPiece(int id);
    void flipPiece(int id);
    void tryAttack(int id, int object);
    void gameOver(bool win);

    bool canAttack();
    bool canWinAttack();
    int canGameOver();

    int getIdByPos();
private:
    MainWindow *win;

    int player_id;
};

#endif // CHESSBOARD_H
