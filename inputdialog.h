#ifndef INPUTDIALOG_H
#define INPUTDIALOG_H

#include <QDialog>

namespace Ui
{
class InputDialog;
}

class InputDialog : public QDialog
{
    Q_OBJECT

public:
    InputDialog(QWidget *parent, QString *ip);
    ~InputDialog();

private slots:
    void on_pushButton_ok_clicked();
    void on_pushButton_cancel_clicked();

private:
    Ui::InputDialog *ui;

    QString *ip;
};

#endif // INPUTDIALOG_H
