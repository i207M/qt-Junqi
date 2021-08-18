#include <QMessageBox>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    gameMode = 0;
    board.setMainWindow(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

Ui::MainWindow *MainWindow::getUi()
{
    return ui;
}


void MainWindow::on_buttonCreateServer_clicked()
{
    actionCreateServer();
}
void MainWindow::on_buttonConnect_clicked()
{
    actionConnectServer();
}
void MainWindow::on_buttonDisconnect_clicked()
{
    actionDisconnect();
}
void MainWindow::on_buttonStart_clicked()
{
    actionStart();
}
void MainWindow::on_buttonDefeat_clicked()
{
    actionAdmitDefeat();
}
void MainWindow::on_actionCreate_a_server_triggered()
{
    actionCreateServer();
}
void MainWindow::on_actionConnect_to_server_triggered()
{
    actionConnectServer();
}
void MainWindow::on_actionDisconnect_triggered()
{
    actionDisconnect();
}
void MainWindow::on_actionStart_triggered()
{
    actionStart();
}
void MainWindow::on_actionAdmit_defeat_triggered()
{
    actionAdmitDefeat();
}
void MainWindow::on_buttonLocal_clicked()
{
    actionSetLocalGame();
}


void MainWindow::actionCreateServer()
{
    ;
}

void MainWindow::actionConnectServer()
{
    ;
}

void MainWindow::actionStart()
{
    if(gameMode == 0) {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Please Select Game Mode."));
    } else if(gameMode == 1) {
        ;
    } else if (gameMode == 2 or gameMode == 3) {
        ;
    }
}

void MainWindow::actionAdmitDefeat()
{
    bool _canAdmitDefeat = canAdmitDefeat();
    if(_canAdmitDefeat) {
        admitDefeat();
    } else {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("You cannot admit defeat yet."));
    }
}

void MainWindow::actionDisconnect()
{
    if (gameMode == 1) {
        ;
    } else if (gameMode == 2) {
        ;
    } else if(gameMode == 3) {
        ;
    }
}

void MainWindow::actionSetLocalGame()
{
    gameMode = 1;
}

void MainWindow::throwError(const char *debug_str)
{
    QMessageBox::critical(this,
                          tr("Error"),
                          tr(debug_str));
    QApplication::exit(1);
}

bool MainWindow::canAdmitDefeat()
{
    ;
}

void MainWindow::admitDefeat()
{
    ;
}

