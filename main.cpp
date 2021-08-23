#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    int ret;
    do {
        MainWindow win;
        win.show();
        ret = app.exec();
    } while(ret == 207);
    return ret;
}
