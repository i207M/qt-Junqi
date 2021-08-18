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

class MainWindow;

class Chessboard
{
public:
    Chessboard();
    ~Chessboard();
    void setMainWindow(MainWindow *_win);
    void display();
    void displayPiece(int id, Pos pos, bool known);
    void move(int id, Pos pre, Pos nxt);
    void selectPiece(int id);
    void deletePiece(int id);
    void flipPiece(int id);
    void clicked();

    bool isKnown();

    int getIdByPos();
    Pos getPosById();
private:
    MainWindow *win;
};

#endif // CHESSBOARD_H
