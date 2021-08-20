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
    ui->buttonDefeat->setDisabled(true);

    timer = new QTimer;
    timeRemaining = 0;

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
        ui->buttonDefeat->setEnabled(true);
    } else if (game_mode == 2 or game_mode == 3) {
        ;
    }
}

void MainWindow::actionAdmitDefeat()
{
    board->tryAdmitDefeat();
}

void MainWindow::actionSetLocalGame()
{
    game_mode = 1;
    log("Set Game Mode to Local.");
}

void MainWindow::gameOver(QString str)
{
    endTimer();
    QMessageBox::information(this,
                             tr("Game Over"),
                             str);
    delete board;
    init();
}

void MainWindow::startTimer()
{
    const int PLAYER_TIME = 20;

    timeRemaining = PLAYER_TIME;
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

    if(timeRemaining <= 0) {
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
    QString str = QString("Player %1").arg(id);
    QString arg_str;
    if(color == 0) {
        arg_str = "<span style=\" font-size:14pt;\"><font color = black>%1</font></span>";
    } else if(color == 1) {
        arg_str = "<span style=\" font-size:14pt;\"><font color = red>%1, Red</font></span>";
    } else {
        arg_str = "<span style=\" font-size:14pt;\"><font color = blue>%1, Blue</font></span>";
    }
    ui->labelYouPlayer->setText(arg_str.arg(str));
}

void MainWindow::changeWhoseTurn(int id)
{
    const QString arg_str("<span style=\" font-size:14pt;\">%1</span>");
    QString str = QString("Player %1").arg(id);
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
