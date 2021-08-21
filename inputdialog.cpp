#include "inputdialog.h"

#include <regex>
using std::regex;
using std::regex_search;

#include <QMessageBox>

#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent, QString *_ip) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
    ip = _ip;
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::on_pushButton_ok_clicked()
{
    // WARNING: 127.0.0.01
    static regex re("^((2(5[0-5]|[0-4]\\d))|[0-1]?\\d{1,2})(\\.((2(5[0-5]|[0-4]\\d))|[0-1]?\\d{1,2})){3}$");

    QString str = ui->lineEdit->text();
    bool match_result = regex_match(str.toStdString(), re);

    if(match_result) {
        *ip = QString(str);
        done(QDialog::Accepted);
    } else {
        QMessageBox::warning(this,
                             tr("Warning"),
                             tr("Please Input Valid IP Address."));
    }
}

void InputDialog::on_pushButton_cancel_clicked()
{
    done(QDialog::Rejected);
}

