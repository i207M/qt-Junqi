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


void MainWindow::on_pushButton_clicked()
{
    MainWindow::on_actionPlay_triggered();
}
void MainWindow::on_pushButton_2_clicked()
{
    MainWindow::on_actionAdmit_defeat_triggered();
}
void MainWindow::on_pushButton_3_clicked()
{
    MainWindow::on_actionCreate_a_server_triggered();
}
void MainWindow::on_pushButton_4_clicked()
{
    MainWindow::on_actionConnect_to_server_triggered();
}
void MainWindow::on_pushButton_5_clicked()
{
    MainWindow::on_actionLocal_triggered();
}


void MainWindow::on_actionCreate_a_server_triggered()
{

}

void MainWindow::on_actionConnect_to_server_triggered()
{

}

void MainWindow::on_actionPlay_triggered()
{
    if(gameMode == 0) {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Please Select Game Mode."));
    } else if (gameMode == 1) {
        ;
    }
}

void MainWindow::on_actionAdmit_defeat_triggered()
{

}

void MainWindow::on_actionLocal_triggered()
{
    gameMode = 1;
}

