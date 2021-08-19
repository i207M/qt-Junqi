#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"
#include "Mdebug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->buttonDisconnect->setDisabled(true);

    init();
    PieceDisplay::initDisplay(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{
    board = nullptr;
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
    if(game_mode == 0) {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Please Select Game Mode."));
    } else if(game_mode == 1) {
        board = new Chessboard(this);
        ui->buttonStart->setDisabled(true);
        ui->buttonLocal->setDisabled(true);
        ui->buttonCreateServer->setDisabled(true);
        ui->buttonConnect->setDisabled(true);
    } else if (game_mode == 2 or game_mode == 3) {
        ;
    }
}

void MainWindow::actionAdmitDefeat()
{
    if(board->getNumTurn() >= 20) {
        ;
    }
}

void MainWindow::actionDisconnect()
{
    if (game_mode == 1) {
        ;
    } else if (game_mode == 2) {
        ;
    } else if(game_mode == 3) {
        ;
    }
}

void MainWindow::actionSetLocalGame()
{
    game_mode = 1;
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
