#ifndef CHESSBOARD_H
#define CHESSBOARD_H
#include <QMainWindow>

#ifndef CLASS_MAINWINDOW
#define CLASS_MAINWINDOW
QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE
#endif

class Chessboard
{
public:
    Chessboard();
    void setMainWindow(Ui::MainWindow);
private:
    Ui::MainWindow *win;
};

#endif // CHESSBOARD_H
