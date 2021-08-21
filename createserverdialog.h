#ifndef CREATESERVERDIALOG_H
#define CREATESERVERDIALOG_H

#include <QDialog>

namespace Ui {
class CreateServerDialog;
}

class CreateServerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CreateServerDialog(QWidget *parent = nullptr);
    ~CreateServerDialog();

private:
    Ui::CreateServerDialog *ui;
};

#endif // CREATESERVERDIALOG_H
