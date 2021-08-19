#include "mainwindow.h"

#include <QString>
#include <QMessageBox>

#include "ui_mainwindow.h"
#include "Mdebug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    game_mode = 0;
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

void MainWindow::actionSetLocalGame()
{
    game_mode = 1;
}

void MainWindow::gameOver(QString str)
{
    QMessageBox::information(this,
                             tr("Game Over"),
                             str);
    delete board;
    endTimer();
    init();
}

void MainWindow::startTimer()
{
    const int PLAYER_TIME = 20;

    timeRemaining = 20;
    ui->lcdNumber->display(timeRemaining);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::oneSecond);
    timer->start(1000);
}

void MainWindow::endTimer()
{
    timer->stop();
}

void MainWindow::oneSecond()
{
    --timeRemaining;
    ui->lcdNumber->display(timeRemaining);

    if(timeRemaining == 0) {
        board->timeOut();
    } else {
        delete timer;
        timer = new QTimer(this);
        connect(timer, &QTimer::timeout, this, &MainWindow::oneSecond);
        timer->start(1000);
    }
}

void MainWindow::throwError(QString str)
{
    QMessageBox::critical(this,
                          tr("Error"),
                          str);
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
