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

    connectButton();
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

void InputDialog::clickButton(QChar c)
{
    QString str = ui->lineEdit->text() + c;
    ui->lineEdit->setText(str);
}

void InputDialog::clickButtonDel()
{
    QString str = ui->lineEdit->text();
    str.chop(1);
    ui->lineEdit->setText(str);
}

void InputDialog::connectButton()
{
    connect(ui->pushButton_0, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('0');
    });
    connect(ui->pushButton_1, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('1');
    });
    connect(ui->pushButton_2, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('2');
    });
    connect(ui->pushButton_3, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('3');
    });
    connect(ui->pushButton_4, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('4');
    });
    connect(ui->pushButton_5, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('5');
    });
    connect(ui->pushButton_6, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('6');
    });
    connect(ui->pushButton_7, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('7');
    });
    connect(ui->pushButton_8, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('8');
    });
    connect(ui->pushButton_9, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('9');
    });
    connect(ui->pushButton_dot, &QPushButton::clicked, this, [ = ]() {
        this->clickButton('.');
    });
    connect(ui->pushButton_del, &QPushButton::clicked, this, [ = ]() {
        this->clickButtonDel();
    });
}
