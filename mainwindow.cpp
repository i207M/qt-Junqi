#include "mainwindow.h"

class QString;
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
    log("Game Start!")
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
    log("Set Game Mode to Local.");
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

void MainWindow::changeYouPlayer(int id, int color)
{
    QString str = QString("Player ") + (id == 1 ? "1" : "2");
    QString arg_str;
    if(color == 0) {
        arg_str = QString("<span style=\" font-size:12pt;\"><font color = black>%1</font></span>");
    } else if(color == 1) {
        arg_str = QString("<span style=\" font-size:12pt;\"><font color = red>%1</font></span>");
    } else {
        arg_str = QString("<span style=\" font-size:12pt;\"><font color = blue>%1</font></span>");
    }
    ui->labelYouPlayer->setText(arg_str.arg(str));
}

void MainWindow::changeWhoseTurn(int id)
{
    const QString arg_str("<span style=\" font-size:12pt;\">%1</span>");
    QString str = QString("Player ") + (id == 1 ? "1" : "2");
    ui->labelWhoseTurn->setText(arg_str.arg(str));
}

void MainWindow::throwError(QString str)
{
    QMessageBox::critical(this,
                          tr("Error"),
                          str);
    QApplication::exit(1);
}

void MainWindow::log(QString str)
{
    ui->textBrowser->append(str);
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
