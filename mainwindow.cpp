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


void MainWindow::actionCreateServer()
{
    server.create();
    client.tryConnect("localhost", P1_PORT, false);
    bool _waitConnection = server.waitConnection();
    if(_waitConnection) {
        gameMode = 1;
    }
}

void MainWindow::actionConnectServer()
{
    bool _showConnectDialog = client.showConnectDialog();
    if(_showConnectDialog) {
        gameMode = 2;
    }
}

void MainWindow::actionStart()
{
    if(gameMode == 0) {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Please Select Game Mode."));
    } else if (gameMode == 1 or gameMode == 2) {
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
    } else {
        throwError("Invalid Game Mode.");
    }
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
