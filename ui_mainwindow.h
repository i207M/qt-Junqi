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
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionCreate_a_server;
    QAction *actionConnect_to_server;
    QAction *actionStart;
    QAction *actionAdmit_defeat;
    QAction *actionDisconnect;
    QWidget *centralwidget;
    QLabel *labelBackground;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTimeRemaining;
    QLCDNumber *lcdNumber;
    QTextBrowser *textBrowser;
    QSpacerItem *verticalSpacer;
    QPushButton *buttonStart;
    QPushButton *buttonDefeat;
    QSpacerItem *verticalSpacer_2;
    QPushButton *buttonLocal;
    QPushButton *buttonCreateServer;
    QPushButton *buttonConnect;
    QPushButton *buttonDisconnect;
    QLabel *label1;
    QLabel *label2;
    QLabel *label3;
    QLabel *label4;
    QLabel *label5;
    QLabel *label9;
    QLabel *label7;
    QLabel *label10;
    QLabel *label6;
    QLabel *label8;
    QLabel *label14;
    QLabel *label12;
    QLabel *label15;
    QLabel *label11;
    QLabel *label13;
    QLabel *label19;
    QLabel *label17;
    QLabel *label20;
    QLabel *label16;
    QLabel *label18;
    QLabel *label24;
    QLabel *label22;
    QLabel *label25;
    QLabel *label21;
    QLabel *label23;
    QLabel *label29;
    QLabel *label27;
    QLabel *label30;
    QLabel *label26;
    QLabel *label28;
    QLabel *label34;
    QLabel *label32;
    QLabel *label35;
    QLabel *label31;
    QLabel *label33;
    QLabel *label39;
    QLabel *label37;
    QLabel *label40;
    QLabel *label36;
    QLabel *label38;
    QLabel *label44;
    QLabel *label42;
    QLabel *label45;
    QLabel *label41;
    QLabel *label43;
    QLabel *label49;
    QLabel *label47;
    QLabel *label50;
    QLabel *label46;
    QLabel *label48;
    QLabel *label54;
    QLabel *label52;
    QLabel *label55;
    QLabel *label51;
    QLabel *label53;
    QLabel *label59;
    QLabel *label57;
    QLabel *label60;
    QLabel *label56;
    QLabel *label58;
    QMenuBar *menubar;
    QMenu *menu;
    QMenu *menuPlay;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(775, 784);
        actionCreate_a_server = new QAction(MainWindow);
        actionCreate_a_server->setObjectName(QString::fromUtf8("actionCreate_a_server"));
        actionConnect_to_server = new QAction(MainWindow);
        actionConnect_to_server->setObjectName(QString::fromUtf8("actionConnect_to_server"));
        actionStart = new QAction(MainWindow);
        actionStart->setObjectName(QString::fromUtf8("actionStart"));
        actionAdmit_defeat = new QAction(MainWindow);
        actionAdmit_defeat->setObjectName(QString::fromUtf8("actionAdmit_defeat"));
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QString::fromUtf8("actionDisconnect"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        labelBackground = new QLabel(centralwidget);
        labelBackground->setObjectName(QString::fromUtf8("labelBackground"));
        labelBackground->setGeometry(QRect(0, 0, 521, 731));
        labelBackground->setPixmap(QPixmap(QString::fromUtf8(":/chessboard/images/empty.png")));
        labelBackground->setScaledContents(true);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(530, 0, 241, 731));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        labelTimeRemaining = new QLabel(verticalLayoutWidget);
        labelTimeRemaining->setObjectName(QString::fromUtf8("labelTimeRemaining"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(5);
        sizePolicy.setHeightForWidth(labelTimeRemaining->sizePolicy().hasHeightForWidth());
        labelTimeRemaining->setSizePolicy(sizePolicy);

        verticalLayout->addWidget(labelTimeRemaining);

        lcdNumber = new QLCDNumber(verticalLayoutWidget);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(15);
        sizePolicy1.setHeightForWidth(lcdNumber->sizePolicy().hasHeightForWidth());
        lcdNumber->setSizePolicy(sizePolicy1);

        verticalLayout->addWidget(lcdNumber);

        textBrowser = new QTextBrowser(verticalLayoutWidget);
        textBrowser->setObjectName(QString::fromUtf8("textBrowser"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(80);
        sizePolicy2.setHeightForWidth(textBrowser->sizePolicy().hasHeightForWidth());
        textBrowser->setSizePolicy(sizePolicy2);

        verticalLayout->addWidget(textBrowser);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        buttonStart = new QPushButton(verticalLayoutWidget);
        buttonStart->setObjectName(QString::fromUtf8("buttonStart"));

        verticalLayout->addWidget(buttonStart);

        buttonDefeat = new QPushButton(verticalLayoutWidget);
        buttonDefeat->setObjectName(QString::fromUtf8("buttonDefeat"));

        verticalLayout->addWidget(buttonDefeat);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        buttonLocal = new QPushButton(verticalLayoutWidget);
        buttonLocal->setObjectName(QString::fromUtf8("buttonLocal"));

        verticalLayout->addWidget(buttonLocal);

        buttonCreateServer = new QPushButton(verticalLayoutWidget);
        buttonCreateServer->setObjectName(QString::fromUtf8("buttonCreateServer"));

        verticalLayout->addWidget(buttonCreateServer);

        buttonConnect = new QPushButton(verticalLayoutWidget);
        buttonConnect->setObjectName(QString::fromUtf8("buttonConnect"));

        verticalLayout->addWidget(buttonConnect);

        buttonDisconnect = new QPushButton(verticalLayoutWidget);
        buttonDisconnect->setObjectName(QString::fromUtf8("buttonDisconnect"));

        verticalLayout->addWidget(buttonDisconnect);

        label1 = new QLabel(centralwidget);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(10, 10, 81, 41));
        label1->setScaledContents(false);
        label2 = new QLabel(centralwidget);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(120, 10, 81, 41));
        label3 = new QLabel(centralwidget);
        label3->setObjectName(QString::fromUtf8("label3"));
        label3->setGeometry(QRect(220, 10, 81, 41));
        label4 = new QLabel(centralwidget);
        label4->setObjectName(QString::fromUtf8("label4"));
        label4->setGeometry(QRect(330, 10, 81, 41));
        label5 = new QLabel(centralwidget);
        label5->setObjectName(QString::fromUtf8("label5"));
        label5->setGeometry(QRect(430, 10, 81, 41));
        label9 = new QLabel(centralwidget);
        label9->setObjectName(QString::fromUtf8("label9"));
        label9->setGeometry(QRect(330, 60, 81, 41));
        label7 = new QLabel(centralwidget);
        label7->setObjectName(QString::fromUtf8("label7"));
        label7->setGeometry(QRect(120, 60, 81, 41));
        label10 = new QLabel(centralwidget);
        label10->setObjectName(QString::fromUtf8("label10"));
        label10->setGeometry(QRect(430, 60, 81, 41));
        label6 = new QLabel(centralwidget);
        label6->setObjectName(QString::fromUtf8("label6"));
        label6->setGeometry(QRect(10, 60, 81, 41));
        label6->setScaledContents(false);
        label8 = new QLabel(centralwidget);
        label8->setObjectName(QString::fromUtf8("label8"));
        label8->setGeometry(QRect(220, 60, 81, 41));
        label14 = new QLabel(centralwidget);
        label14->setObjectName(QString::fromUtf8("label14"));
        label14->setGeometry(QRect(330, 110, 81, 41));
        label12 = new QLabel(centralwidget);
        label12->setObjectName(QString::fromUtf8("label12"));
        label12->setGeometry(QRect(120, 110, 81, 41));
        label15 = new QLabel(centralwidget);
        label15->setObjectName(QString::fromUtf8("label15"));
        label15->setGeometry(QRect(430, 110, 81, 41));
        label11 = new QLabel(centralwidget);
        label11->setObjectName(QString::fromUtf8("label11"));
        label11->setGeometry(QRect(10, 110, 81, 41));
        label11->setScaledContents(false);
        label13 = new QLabel(centralwidget);
        label13->setObjectName(QString::fromUtf8("label13"));
        label13->setGeometry(QRect(220, 110, 81, 41));
        label19 = new QLabel(centralwidget);
        label19->setObjectName(QString::fromUtf8("label19"));
        label19->setGeometry(QRect(330, 160, 81, 41));
        label17 = new QLabel(centralwidget);
        label17->setObjectName(QString::fromUtf8("label17"));
        label17->setGeometry(QRect(120, 160, 81, 41));
        label20 = new QLabel(centralwidget);
        label20->setObjectName(QString::fromUtf8("label20"));
        label20->setGeometry(QRect(430, 160, 81, 41));
        label16 = new QLabel(centralwidget);
        label16->setObjectName(QString::fromUtf8("label16"));
        label16->setGeometry(QRect(10, 160, 81, 41));
        label16->setScaledContents(false);
        label18 = new QLabel(centralwidget);
        label18->setObjectName(QString::fromUtf8("label18"));
        label18->setGeometry(QRect(220, 160, 81, 41));
        label24 = new QLabel(centralwidget);
        label24->setObjectName(QString::fromUtf8("label24"));
        label24->setGeometry(QRect(330, 210, 81, 41));
        label22 = new QLabel(centralwidget);
        label22->setObjectName(QString::fromUtf8("label22"));
        label22->setGeometry(QRect(120, 210, 81, 41));
        label25 = new QLabel(centralwidget);
        label25->setObjectName(QString::fromUtf8("label25"));
        label25->setGeometry(QRect(430, 210, 81, 41));
        label21 = new QLabel(centralwidget);
        label21->setObjectName(QString::fromUtf8("label21"));
        label21->setGeometry(QRect(10, 210, 81, 41));
        label21->setScaledContents(false);
        label23 = new QLabel(centralwidget);
        label23->setObjectName(QString::fromUtf8("label23"));
        label23->setGeometry(QRect(220, 210, 81, 41));
        label29 = new QLabel(centralwidget);
        label29->setObjectName(QString::fromUtf8("label29"));
        label29->setGeometry(QRect(330, 260, 81, 41));
        label27 = new QLabel(centralwidget);
        label27->setObjectName(QString::fromUtf8("label27"));
        label27->setGeometry(QRect(120, 260, 81, 41));
        label30 = new QLabel(centralwidget);
        label30->setObjectName(QString::fromUtf8("label30"));
        label30->setGeometry(QRect(430, 260, 81, 41));
        label26 = new QLabel(centralwidget);
        label26->setObjectName(QString::fromUtf8("label26"));
        label26->setGeometry(QRect(10, 260, 81, 41));
        label26->setScaledContents(false);
        label28 = new QLabel(centralwidget);
        label28->setObjectName(QString::fromUtf8("label28"));
        label28->setGeometry(QRect(220, 260, 81, 41));
        label34 = new QLabel(centralwidget);
        label34->setObjectName(QString::fromUtf8("label34"));
        label34->setGeometry(QRect(330, 420, 81, 41));
        label32 = new QLabel(centralwidget);
        label32->setObjectName(QString::fromUtf8("label32"));
        label32->setGeometry(QRect(120, 420, 81, 41));
        label35 = new QLabel(centralwidget);
        label35->setObjectName(QString::fromUtf8("label35"));
        label35->setGeometry(QRect(430, 420, 81, 41));
        label31 = new QLabel(centralwidget);
        label31->setObjectName(QString::fromUtf8("label31"));
        label31->setGeometry(QRect(10, 420, 81, 41));
        label31->setScaledContents(false);
        label33 = new QLabel(centralwidget);
        label33->setObjectName(QString::fromUtf8("label33"));
        label33->setGeometry(QRect(220, 420, 81, 41));
        label39 = new QLabel(centralwidget);
        label39->setObjectName(QString::fromUtf8("label39"));
        label39->setGeometry(QRect(330, 470, 81, 41));
        label37 = new QLabel(centralwidget);
        label37->setObjectName(QString::fromUtf8("label37"));
        label37->setGeometry(QRect(120, 470, 81, 41));
        label40 = new QLabel(centralwidget);
        label40->setObjectName(QString::fromUtf8("label40"));
        label40->setGeometry(QRect(430, 470, 81, 41));
        label36 = new QLabel(centralwidget);
        label36->setObjectName(QString::fromUtf8("label36"));
        label36->setGeometry(QRect(10, 470, 81, 41));
        label36->setScaledContents(false);
        label38 = new QLabel(centralwidget);
        label38->setObjectName(QString::fromUtf8("label38"));
        label38->setGeometry(QRect(220, 470, 81, 41));
        label44 = new QLabel(centralwidget);
        label44->setObjectName(QString::fromUtf8("label44"));
        label44->setGeometry(QRect(330, 520, 81, 41));
        label42 = new QLabel(centralwidget);
        label42->setObjectName(QString::fromUtf8("label42"));
        label42->setGeometry(QRect(120, 520, 81, 41));
        label45 = new QLabel(centralwidget);
        label45->setObjectName(QString::fromUtf8("label45"));
        label45->setGeometry(QRect(430, 520, 81, 41));
        label41 = new QLabel(centralwidget);
        label41->setObjectName(QString::fromUtf8("label41"));
        label41->setGeometry(QRect(10, 520, 81, 41));
        label41->setScaledContents(false);
        label43 = new QLabel(centralwidget);
        label43->setObjectName(QString::fromUtf8("label43"));
        label43->setGeometry(QRect(220, 520, 81, 41));
        label49 = new QLabel(centralwidget);
        label49->setObjectName(QString::fromUtf8("label49"));
        label49->setGeometry(QRect(330, 570, 81, 41));
        label47 = new QLabel(centralwidget);
        label47->setObjectName(QString::fromUtf8("label47"));
        label47->setGeometry(QRect(120, 570, 81, 41));
        label50 = new QLabel(centralwidget);
        label50->setObjectName(QString::fromUtf8("label50"));
        label50->setGeometry(QRect(430, 570, 81, 41));
        label46 = new QLabel(centralwidget);
        label46->setObjectName(QString::fromUtf8("label46"));
        label46->setGeometry(QRect(10, 570, 81, 41));
        label46->setScaledContents(false);
        label48 = new QLabel(centralwidget);
        label48->setObjectName(QString::fromUtf8("label48"));
        label48->setGeometry(QRect(220, 570, 81, 41));
        label54 = new QLabel(centralwidget);
        label54->setObjectName(QString::fromUtf8("label54"));
        label54->setGeometry(QRect(330, 630, 81, 41));
        label52 = new QLabel(centralwidget);
        label52->setObjectName(QString::fromUtf8("label52"));
        label52->setGeometry(QRect(120, 630, 81, 41));
        label55 = new QLabel(centralwidget);
        label55->setObjectName(QString::fromUtf8("label55"));
        label55->setGeometry(QRect(430, 630, 81, 41));
        label51 = new QLabel(centralwidget);
        label51->setObjectName(QString::fromUtf8("label51"));
        label51->setGeometry(QRect(10, 630, 81, 41));
        label51->setScaledContents(false);
        label53 = new QLabel(centralwidget);
        label53->setObjectName(QString::fromUtf8("label53"));
        label53->setGeometry(QRect(220, 630, 81, 41));
        label59 = new QLabel(centralwidget);
        label59->setObjectName(QString::fromUtf8("label59"));
        label59->setGeometry(QRect(330, 680, 81, 41));
        label57 = new QLabel(centralwidget);
        label57->setObjectName(QString::fromUtf8("label57"));
        label57->setGeometry(QRect(120, 680, 81, 41));
        label60 = new QLabel(centralwidget);
        label60->setObjectName(QString::fromUtf8("label60"));
        label60->setGeometry(QRect(430, 680, 81, 41));
        label56 = new QLabel(centralwidget);
        label56->setObjectName(QString::fromUtf8("label56"));
        label56->setGeometry(QRect(10, 680, 81, 41));
        label56->setScaledContents(false);
        label58 = new QLabel(centralwidget);
        label58->setObjectName(QString::fromUtf8("label58"));
        label58->setGeometry(QRect(220, 680, 81, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 775, 23));
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
        menu->addAction(actionConnect_to_server);
        menu->addSeparator();
        menu->addAction(actionDisconnect);
        menuPlay->addAction(actionStart);
        menuPlay->addAction(actionAdmit_defeat);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\345\206\233\346\243\213", nullptr));
        actionCreate_a_server->setText(QCoreApplication::translate("MainWindow", "Create a Server", nullptr));
        actionConnect_to_server->setText(QCoreApplication::translate("MainWindow", "Connect to Server", nullptr));
        actionStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        actionAdmit_defeat->setText(QCoreApplication::translate("MainWindow", "Admit Defeat", nullptr));
        actionDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        labelBackground->setText(QString());
        labelTimeRemaining->setText(QCoreApplication::translate("MainWindow", "<html><head/><body><p><span style=\" font-size:14pt; font-weight:600;\">Time Remaining:</span></p></body></html>", nullptr));
        buttonStart->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        buttonDefeat->setText(QCoreApplication::translate("MainWindow", "Admit Defeat", nullptr));
        buttonLocal->setText(QCoreApplication::translate("MainWindow", "Set Local Game", nullptr));
        buttonCreateServer->setText(QCoreApplication::translate("MainWindow", "Create a Server", nullptr));
        buttonConnect->setText(QCoreApplication::translate("MainWindow", "Connect to Server", nullptr));
        buttonDisconnect->setText(QCoreApplication::translate("MainWindow", "Disconnect", nullptr));
        label1->setText(QString());
        label2->setText(QString());
        label3->setText(QString());
        label4->setText(QString());
        label5->setText(QString());
        label9->setText(QString());
        label7->setText(QString());
        label10->setText(QString());
        label6->setText(QString());
        label8->setText(QString());
        label14->setText(QString());
        label12->setText(QString());
        label15->setText(QString());
        label11->setText(QString());
        label13->setText(QString());
        label19->setText(QString());
        label17->setText(QString());
        label20->setText(QString());
        label16->setText(QString());
        label18->setText(QString());
        label24->setText(QString());
        label22->setText(QString());
        label25->setText(QString());
        label21->setText(QString());
        label23->setText(QString());
        label29->setText(QString());
        label27->setText(QString());
        label30->setText(QString());
        label26->setText(QString());
        label28->setText(QString());
        label34->setText(QString());
        label32->setText(QString());
        label35->setText(QString());
        label31->setText(QString());
        label33->setText(QString());
        label39->setText(QString());
        label37->setText(QString());
        label40->setText(QString());
        label36->setText(QString());
        label38->setText(QString());
        label44->setText(QString());
        label42->setText(QString());
        label45->setText(QString());
        label41->setText(QString());
        label43->setText(QString());
        label49->setText(QString());
        label47->setText(QString());
        label50->setText(QString());
        label46->setText(QString());
        label48->setText(QString());
        label54->setText(QString());
        label52->setText(QString());
        label55->setText(QString());
        label51->setText(QString());
        label53->setText(QString());
        label59->setText(QString());
        label57->setText(QString());
        label60->setText(QString());
        label56->setText(QString());
        label58->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        menuPlay->setTitle(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
