#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "chessboard.h"
#include "server.h"
#include "client.h"

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
    bool canAdmitDefeat();
    void admitDefeat();

private slots:
    void on_actionCreate_a_server_triggered();
    void on_actionConnect_to_server_triggered();
    void on_actionStart_triggered();
    void on_actionAdmit_defeat_triggered();
    void on_actionLocal_triggered();

    void on_buttonCreateServer_clicked();
    void on_buttonConnect_clicked();
    void on_buttonStart_clicked();
    void on_buttonDefeat_clicked();

private:
    Ui::MainWindow *ui;

    Chessboard board;
    Server server;
    Client client;

    int gameMode;
};
#endif // MAINWINDOW_H
