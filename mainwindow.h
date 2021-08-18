#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void actionDisconnect();
    void actionStart();
    void actionAdmitDefeat();
    void actionSetLocalGame();

    bool canAdmitDefeat();
    void admitDefeat();

    void throwError(const char *debug_str);
    void log(const char *debug_str);

private slots:
    void on_actionCreate_a_server_triggered();
    void on_actionConnect_to_server_triggered();
    void on_actionDisconnect_triggered();
    void on_actionStart_triggered();
    void on_actionAdmit_defeat_triggered();

    void on_buttonCreateServer_clicked();
    void on_buttonConnect_clicked();
    void on_buttonDisconnect_clicked();
    void on_buttonStart_clicked();
    void on_buttonDefeat_clicked();
    void on_buttonLocal_clicked();

private:
    Ui::MainWindow *ui;

    Chessboard board;

    int gameMode;
};
#endif // MAINWINDOW_H
