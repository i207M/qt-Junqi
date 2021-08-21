#include "createserverdialog.h"
#include "ui_createserverdialog.h"

CreateServerDialog::CreateServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateServerDialog)
{
    ui->setupUi(this);
}

CreateServerDialog::~CreateServerDialog()
{
    delete ui;
}

void CreateServerDialog::showIp(QString ip)
{
    ui->textBrowser->append(ip);
}
