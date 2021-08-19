#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTime>
#include <QTimer>

#include "chessboard.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void actionCreateServer();
    void actionConnectServer();
    void actionStart();
    void actionAdmitDefeat();
    void actionSetLocalGame();

    void init();
    void gameOver(QString str);
    void startTimer();
    void endTimer();
    void oneSecond();

    void throwError(QString str);
    void log(QString str);

    Ui::MainWindow *ui;

private slots:
    void on_actionCreate_a_server_triggered();
    void on_actionConnect_to_server_triggered();
    void on_actionStart_triggered();
    void on_actionAdmit_defeat_triggered();

    void on_buttonCreateServer_clicked();
    void on_buttonConnect_clicked();
    void on_buttonStart_clicked();
    void on_buttonDefeat_clicked();
    void on_buttonLocal_clicked();

private:
    QTimer *timer;
    int timeRemaining;

    Chessboard *board;

    int game_mode;
};
#endif // MAINWINDOW_H
