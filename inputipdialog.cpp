#include "inputipdialog.h"
#include "ui_inputipdialog.h"

InputIpDialog::InputIpDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputIpDialog)
{
    ui->setupUi(this);
}

InputIpDialog::~InputIpDialog()
{
    delete ui;
}
