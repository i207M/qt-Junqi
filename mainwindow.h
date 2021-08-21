#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTime>
#include <QTimer>
#include <QNetworkInterface>

#include "chessboard.h"
#include "netboard.h"

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

    void gameOver(QString str);

    // timer related
    void startTimer();
    void endTimer();
    void oneSecond();

    // ui related
    void changeYouPlayer(int id, int color);
    void changeWhoseTurn(int id);
    // void throwError(QString str);
    void log(QString str);

    // network related
    static QString getIp();
    void connectSuccessfully();

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

    void on_actionRandomly_Kill_triggered();
    void on_actionDisconnect_triggered();

private:
    QTimer *timer;
    int timeRemaining;

    Chessboard *board;
    int game_mode;  // 1: local, 2: server, 3: client

    // network related
    QString ip;
};
#endif // MAINWINDOW_H
