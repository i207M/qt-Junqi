#include "inputdialog.h"

#include <regex>
using std::regex;
using std::regex_search;

#include "ui_inputdialog.h"

InputDialog::InputDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::InputDialog)
{
    ui->setupUi(this);
}

InputDialog::~InputDialog()
{
    delete ui;
}

void InputDialog::on_pushButton_ok_clicked()
{
    static regex re("^((2(5[0-5]|[0-4]\\d))|[0-1]?\\d{1,2})(\\.((2(5[0-5]|[0-4]\\d))|[0-1]?\\d{1,2})){3}$");

    QString str = ui->lineEdit->text();
    bool match_result = regex_search(str.toStdString(), re);

    if(match_result) {
        done(QDialog::Accepted);
    } else {
        // TODO
    }
}

void InputDialog::on_pushButton_cancel_clicked()
{
    done(QDialog::Rejected);
}

