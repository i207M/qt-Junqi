#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    board = nullptr;
    gameMode = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
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
        board = new Chessboard(this);
        ui->buttonStart->setDisabled(true);
    } else if (gameMode == 2 or gameMode == 3) {
        ;
    }
}

void MainWindow::actionAdmitDefeat()
{
    board->tryAdmitDefeat();
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

void MainWindow::paintEvent(QPaintEvent *)
{
    if(board == nullptr) {
        return;
    } else {
        board->displayAll();
    }
}

void MainWindow::throwError(const char *debug_str)
{
    QMessageBox::critical(this,
                          tr("Error"),
                          tr(debug_str));
    QApplication::exit(1);
}

#pragma region
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
#pragma endregion
