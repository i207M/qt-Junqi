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


void MainWindow::on_buttonCreateServer_clicked()
{
    MainWindow::on_actionCreate_a_server_triggered();
}
void MainWindow::on_buttonConnect_clicked()
{
    MainWindow::on_actionCreate_a_server_triggered();
}
void MainWindow::on_buttonStart_clicked()
{
    MainWindow::on_actionStart_triggered();
}
void MainWindow::on_buttonDefeat_clicked()
{
    MainWindow::on_actionAdmit_defeat_triggered();
}


void MainWindow::on_actionCreate_a_server_triggered()
{
    server.create();
    client.tryConnect("localhost", P1_PORT, false);
    bool ret = server.waitConnection();
    if(ret) {
        gameMode = 2;
    }
}

void MainWindow::on_actionConnect_to_server_triggered()
{
    bool ret = client.showConnectDialog();
    if(ret) {
        gameMode = 2;
    }
}

void MainWindow::on_actionStart_triggered()
{
    if(gameMode == 0) {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Please Select Game Mode."));
    } else if (gameMode == 2) {
        ;
    }
}

void MainWindow::on_actionAdmit_defeat_triggered()
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

void MainWindow::on_actionLocal_triggered()
{
    // gameMode = 1;
    QMessageBox::information(this,
                             tr("Deprecated"),
                             tr("Not implemented."));
}

