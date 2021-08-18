#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QMainWindow>

class MainWindow;

class Chessboard
{
public:
    Chessboard();
    void setMainWindow(MainWindow *);
private:
    MainWindow *win;
};

#endif // CHESSBOARD_H
