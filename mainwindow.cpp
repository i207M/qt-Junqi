#include "mainwindow.h"

#include <QMessageBox>

#include "ui_mainwindow.h"
#include "createserverdialog.h"
#include "inputdialog.h"
#include "m_debug.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->buttonDefeat->setDisabled(true);

    board = nullptr;
    game_mode = 0;
    ip = "-1";

    PieceDisplay::initDisplay(ui);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::actionCreateServer()
{
    CreateServerDialog dlg(this);
    QList<QHostAddress> list = QNetworkInterface::allAddresses();
    for(const auto &address : list) {
        if(address.protocol() == QAbstractSocket::IPv4Protocol) {
            dlg.showIp(address.toString());
            log("Your IP address is " + address.toString());
        }
    }
    if(dlg.exec() != QDialog::Accepted) {
        return;
    }

    game_mode = 2;
    ip = "0";

    board = new Netboard(this, ip);

    ui->buttonLocal->setDisabled(true);
    ui->buttonCreateServer->setDisabled(true);
    ui->buttonConnect->setDisabled(true);

    log("Set Game Mode to Server.");
}

void MainWindow::actionConnectServer()
{
    InputDialog dlg(this);
    if(dlg.exec() != QDialog::Accepted) {
        return;
    }

    game_mode = 3;
    ip = "127.0.0.1";  // TODO

    board = new Netboard(this, ip);

    ui->buttonLocal->setDisabled(true);
    ui->buttonCreateServer->setDisabled(true);
    ui->buttonConnect->setDisabled(true);

    log("Set Game Mode to Client.");
}

void MainWindow::actionStart()
{
    if(game_mode == 0) {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Please Select Game Mode."));
        return;
    }

    if(game_mode == 1) {
        board = new Chessboard(this);
        board->localPressStart();
    } else if (game_mode == 2 or game_mode == 3) {
        board->localPressStart();
    } else {
        err("Error Gamemode");
    }

    ui->buttonStart->setDisabled(true);
    ui->buttonDefeat->setEnabled(true);
}

void MainWindow::actionAdmitDefeat()
{
    board->tryAdmitDefeat();
}

void MainWindow::actionSetLocalGame()
{
    game_mode = 1;
    ui->buttonLocal->setDisabled(true);
    ui->buttonCreateServer->setDisabled(true);
    ui->buttonConnect->setDisabled(true);

    log("Set Game Mode to Local.");
}

void MainWindow::gameOver(QString str)
{
    board->endTimer();
    board->stopHeartBeat();
    QMessageBox::information(this,
                             tr("Game Over"),
                             str);
    QMessageBox::information(this,
                             tr("Goodbye"),
                             tr("The Program is about to Close."));
    qApp->quit();
}

void MainWindow::changeYouPlayer(int id, int color)
{
    QString str = QString("Player %1").arg(id);
    QString arg_str;
    if(color == 1) {
        arg_str = QString("<span style=\" font-size:14pt;\"><font color = red>%1, Red</font></span>");
    } else if(color == 2) {
        arg_str = QString("<span style=\" font-size:14pt;\"><font color = blue>%1, Blue</font></span>");
    } else {
        arg_str = QString("<span style=\" font-size:14pt;\"><font color = black>%1</font></span>");
    }
    ui->labelYouPlayer->setText(arg_str.arg(str));
}

void MainWindow::changeWhoseTurn(int id)
{
    const QString arg_str("<span style=\" font-size:14pt;\">%1</span>");
    QString str = QString("Player %1").arg(id);
    ui->labelWhoseTurn->setText(arg_str.arg(str));
}

// void MainWindow::throwError(QString str)
// {
//     QMessageBox::critical(this,
//                           tr("Error"),
//                           str);
//     qApp->exit(1);
// }

void MainWindow::log(QString str)
{
    ui->textBrowser->append(str);
}

void MainWindow::on_actionRandomly_Kill_triggered()
{
    board->debugRandomlyKill();
}

void MainWindow::on_actionDisconnect_triggered()
{
    board->stopHeartBeat();
}

// QString MainWindow::getOneIp()
// {
//     QList<QHostAddress> list = QNetworkInterface::allAddresses();
//     for(const auto &address : list) {
//         qDebug() << address.toString();
//         if(address.protocol() == QAbstractSocket::IPv4Protocol) {
//             return address.toString();
//         }
//     }
//     return "-1";
// }

void MainWindow::connectSuccessfully()
{
    log("Connect Successfully.");
    // TODO: QMessage::information
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
