#ifndef INPUTIPDIALOG_H
#define INPUTIPDIALOG_H

#include <QWidget>

namespace Ui {
class InputIpDialog;
}

class InputIpDialog : public QWidget
{
    Q_OBJECT

public:
    explicit InputIpDialog(QWidget *parent = nullptr);
    ~InputIpDialog();

private:
    Ui::InputIpDialog *ui;
};

#endif // INPUTIPDIALOG_H
