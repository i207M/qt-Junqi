#ifndef CLIENTWAITCONNECTDIALOG_H
#define CLIENTWAITCONNECTDIALOG_H

#include <QDialog>

namespace Ui {
class ClientWaitConnectDialog;
}

class ClientWaitConnectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ClientWaitConnectDialog(QWidget *parent = nullptr);
    ~ClientWaitConnectDialog();

private:
    Ui::ClientWaitConnectDialog *ui;
};

#endif // CLIENTWAITCONNECTDIALOG_H
