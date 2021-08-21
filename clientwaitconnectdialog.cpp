#include "clientwaitconnectdialog.h"
#include "ui_clientwaitconnectdialog.h"

ClientWaitConnectDialog::ClientWaitConnectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientWaitConnectDialog)
{
    ui->setupUi(this);
}

ClientWaitConnectDialog::~ClientWaitConnectDialog()
{
    delete ui;
}
