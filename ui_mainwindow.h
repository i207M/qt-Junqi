/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreate_a_server;
    QAction *actionConnect_to_server;
    QAction *actionPlay;
    QAction *actionAdmit_defeat;
    QWidget *centralwidget;
    QLabel *label;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuPlay;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1231, 1586);
        actionCreate_a_server = new QAction(MainWindow);
        actionCreate_a_server->setObjectName(QString::fromUtf8("actionCreate_a_server"));
        actionConnect_to_server = new QAction(MainWindow);
        actionConnect_to_server->setObjectName(QString::fromUtf8("actionConnect_to_server"));
        actionPlay = new QAction(MainWindow);
        actionPlay->setObjectName(QString::fromUtf8("actionPlay"));
        actionAdmit_defeat = new QAction(MainWindow);
        actionAdmit_defeat->setObjectName(QString::fromUtf8("actionAdmit_defeat"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 1105, 1536));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setPixmap(QPixmap(QString::fromUtf8(":/chessboard/images/empty.png")));
        label->setScaledContents(true);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1231, 26));
        menu = new QMenu(menubar);
        menu->setObjectName(QString::fromUtf8("menu"));
        menuPlay = new QMenu(menubar);
        menuPlay->setObjectName(QString::fromUtf8("menuPlay"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menu->menuAction());
        menubar->addAction(menuPlay->menuAction());
        menu->addAction(actionCreate_a_server);
        menu->addSeparator();
        menu->addAction(actionConnect_to_server);
        menuPlay->addAction(actionPlay);
        menuPlay->addAction(actionAdmit_defeat);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\206\233\346\243\213", nullptr));
        actionCreate_a_server->setText(QCoreApplication::translate("MainWindow", "Create server", nullptr));
        actionConnect_to_server->setText(QCoreApplication::translate("MainWindow", "Connect to server", nullptr));
        actionPlay->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionAdmit_defeat->setText(QCoreApplication::translate("MainWindow", "Admit defeat", nullptr));
        label->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        menuPlay->setTitle(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
