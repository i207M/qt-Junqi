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
    QLabel *label_1;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLabel *label_22;
    QLabel *label_23;
    QLabel *label_24;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLabel *label_28;
    QLabel *label_29;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_32;
    QLabel *label_33;
    QLabel *label_34;
    QLabel *label_35;
    QLabel *label_36;
    QLabel *label_37;
    QLabel *label_38;
    QLabel *label_39;
    QLabel *label_40;
    QLabel *label_41;
    QLabel *label_42;
    QLabel *label_43;
    QLabel *label_44;
    QLabel *label_45;
    QLabel *label_46;
    QLabel *label_47;
    QLabel *label_48;
    QLabel *label_49;
    QLabel *label_50;
    QLabel *label_51;
    QLabel *label_52;
    QLabel *label_53;
    QLabel *label_54;
    QLabel *label_55;
    QLabel *label_56;
    QLabel *label_57;
    QLabel *label_58;
    QLabel *label_59;
    QLabel *label_60;
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

        label_1 = new QLabel(centralwidget);
        label_1->setObjectName(QString::fromUtf8("label_1"));
        label_1->setGeometry(QRect(10, 10, 81, 41));
        label_1->setScaledContents(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(120, 10, 81, 41));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(220, 10, 81, 41));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(330, 10, 81, 41));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(430, 10, 81, 41));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(330, 60, 81, 41));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(120, 60, 81, 41));
        label_8 = new QLabel(centralwidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(430, 60, 81, 41));
        label_9 = new QLabel(centralwidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 60, 81, 41));
        label_9->setScaledContents(false);
        label_10 = new QLabel(centralwidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(220, 60, 81, 41));
        label_11 = new QLabel(centralwidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(330, 110, 81, 41));
        label_12 = new QLabel(centralwidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(120, 110, 81, 41));
        label_13 = new QLabel(centralwidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(430, 110, 81, 41));
        label_14 = new QLabel(centralwidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(10, 110, 81, 41));
        label_14->setScaledContents(false);
        label_15 = new QLabel(centralwidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(220, 110, 81, 41));
        label_16 = new QLabel(centralwidget);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(330, 160, 81, 41));
        label_17 = new QLabel(centralwidget);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(120, 160, 81, 41));
        label_18 = new QLabel(centralwidget);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(430, 160, 81, 41));
        label_19 = new QLabel(centralwidget);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(10, 160, 81, 41));
        label_19->setScaledContents(false);
        label_20 = new QLabel(centralwidget);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(220, 160, 81, 41));
        label_21 = new QLabel(centralwidget);
        label_21->setObjectName(QString::fromUtf8("label_21"));
        label_21->setGeometry(QRect(330, 210, 81, 41));
        label_22 = new QLabel(centralwidget);
        label_22->setObjectName(QString::fromUtf8("label_22"));
        label_22->setGeometry(QRect(120, 210, 81, 41));
        label_23 = new QLabel(centralwidget);
        label_23->setObjectName(QString::fromUtf8("label_23"));
        label_23->setGeometry(QRect(430, 210, 81, 41));
        label_24 = new QLabel(centralwidget);
        label_24->setObjectName(QString::fromUtf8("label_24"));
        label_24->setGeometry(QRect(10, 210, 81, 41));
        label_24->setScaledContents(false);
        label_25 = new QLabel(centralwidget);
        label_25->setObjectName(QString::fromUtf8("label_25"));
        label_25->setGeometry(QRect(220, 210, 81, 41));
        label_26 = new QLabel(centralwidget);
        label_26->setObjectName(QString::fromUtf8("label_26"));
        label_26->setGeometry(QRect(330, 260, 81, 41));
        label_27 = new QLabel(centralwidget);
        label_27->setObjectName(QString::fromUtf8("label_27"));
        label_27->setGeometry(QRect(120, 260, 81, 41));
        label_28 = new QLabel(centralwidget);
        label_28->setObjectName(QString::fromUtf8("label_28"));
        label_28->setGeometry(QRect(430, 260, 81, 41));
        label_29 = new QLabel(centralwidget);
        label_29->setObjectName(QString::fromUtf8("label_29"));
        label_29->setGeometry(QRect(10, 260, 81, 41));
        label_29->setScaledContents(false);
        label_30 = new QLabel(centralwidget);
        label_30->setObjectName(QString::fromUtf8("label_30"));
        label_30->setGeometry(QRect(220, 260, 81, 41));
        label_31 = new QLabel(centralwidget);
        label_31->setObjectName(QString::fromUtf8("label_31"));
        label_31->setGeometry(QRect(330, 420, 81, 41));
        label_32 = new QLabel(centralwidget);
        label_32->setObjectName(QString::fromUtf8("label_32"));
        label_32->setGeometry(QRect(120, 420, 81, 41));
        label_33 = new QLabel(centralwidget);
        label_33->setObjectName(QString::fromUtf8("label_33"));
        label_33->setGeometry(QRect(430, 420, 81, 41));
        label_34 = new QLabel(centralwidget);
        label_34->setObjectName(QString::fromUtf8("label_34"));
        label_34->setGeometry(QRect(10, 420, 81, 41));
        label_34->setScaledContents(false);
        label_35 = new QLabel(centralwidget);
        label_35->setObjectName(QString::fromUtf8("label_35"));
        label_35->setGeometry(QRect(220, 420, 81, 41));
        label_36 = new QLabel(centralwidget);
        label_36->setObjectName(QString::fromUtf8("label_36"));
        label_36->setGeometry(QRect(330, 470, 81, 41));
        label_37 = new QLabel(centralwidget);
        label_37->setObjectName(QString::fromUtf8("label_37"));
        label_37->setGeometry(QRect(120, 470, 81, 41));
        label_38 = new QLabel(centralwidget);
        label_38->setObjectName(QString::fromUtf8("label_38"));
        label_38->setGeometry(QRect(430, 470, 81, 41));
        label_39 = new QLabel(centralwidget);
        label_39->setObjectName(QString::fromUtf8("label_39"));
        label_39->setGeometry(QRect(10, 470, 81, 41));
        label_39->setScaledContents(false);
        label_40 = new QLabel(centralwidget);
        label_40->setObjectName(QString::fromUtf8("label_40"));
        label_40->setGeometry(QRect(220, 470, 81, 41));
        label_41 = new QLabel(centralwidget);
        label_41->setObjectName(QString::fromUtf8("label_41"));
        label_41->setGeometry(QRect(330, 520, 81, 41));
        label_42 = new QLabel(centralwidget);
        label_42->setObjectName(QString::fromUtf8("label_42"));
        label_42->setGeometry(QRect(120, 520, 81, 41));
        label_43 = new QLabel(centralwidget);
        label_43->setObjectName(QString::fromUtf8("label_43"));
        label_43->setGeometry(QRect(430, 520, 81, 41));
        label_44 = new QLabel(centralwidget);
        label_44->setObjectName(QString::fromUtf8("label_44"));
        label_44->setGeometry(QRect(10, 520, 81, 41));
        label_44->setScaledContents(false);
        label_45 = new QLabel(centralwidget);
        label_45->setObjectName(QString::fromUtf8("label_45"));
        label_45->setGeometry(QRect(220, 520, 81, 41));
        label_46 = new QLabel(centralwidget);
        label_46->setObjectName(QString::fromUtf8("label_46"));
        label_46->setGeometry(QRect(330, 570, 81, 41));
        label_47 = new QLabel(centralwidget);
        label_47->setObjectName(QString::fromUtf8("label_47"));
        label_47->setGeometry(QRect(120, 570, 81, 41));
        label_48 = new QLabel(centralwidget);
        label_48->setObjectName(QString::fromUtf8("label_48"));
        label_48->setGeometry(QRect(430, 570, 81, 41));
        label_49 = new QLabel(centralwidget);
        label_49->setObjectName(QString::fromUtf8("label_49"));
        label_49->setGeometry(QRect(10, 570, 81, 41));
        label_49->setScaledContents(false);
        label_50 = new QLabel(centralwidget);
        label_50->setObjectName(QString::fromUtf8("label_50"));
        label_50->setGeometry(QRect(220, 570, 81, 41));
        label_51 = new QLabel(centralwidget);
        label_51->setObjectName(QString::fromUtf8("label_51"));
        label_51->setGeometry(QRect(330, 630, 81, 41));
        label_52 = new QLabel(centralwidget);
        label_52->setObjectName(QString::fromUtf8("label_52"));
        label_52->setGeometry(QRect(120, 630, 81, 41));
        label_53 = new QLabel(centralwidget);
        label_53->setObjectName(QString::fromUtf8("label_53"));
        label_53->setGeometry(QRect(430, 630, 81, 41));
        label_54 = new QLabel(centralwidget);
        label_54->setObjectName(QString::fromUtf8("label_54"));
        label_54->setGeometry(QRect(10, 630, 81, 41));
        label_54->setScaledContents(false);
        label_55 = new QLabel(centralwidget);
        label_55->setObjectName(QString::fromUtf8("label_55"));
        label_55->setGeometry(QRect(220, 630, 81, 41));
        label_56 = new QLabel(centralwidget);
        label_56->setObjectName(QString::fromUtf8("label_56"));
        label_56->setGeometry(QRect(330, 680, 81, 41));
        label_57 = new QLabel(centralwidget);
        label_57->setObjectName(QString::fromUtf8("label_57"));
        label_57->setGeometry(QRect(120, 680, 81, 41));
        label_58 = new QLabel(centralwidget);
        label_58->setObjectName(QString::fromUtf8("label_58"));
        label_58->setGeometry(QRect(430, 680, 81, 41));
        label_59 = new QLabel(centralwidget);
        label_59->setObjectName(QString::fromUtf8("label_59"));
        label_59->setGeometry(QRect(10, 680, 81, 41));
        label_59->setScaledContents(false);
        label_60 = new QLabel(centralwidget);
        label_60->setObjectName(QString::fromUtf8("label_60"));
        label_60->setGeometry(QRect(220, 680, 81, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 775, 26));
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
        label_1->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        label_4->setText(QString());
        label_5->setText(QString());
        label_6->setText(QString());
        label_7->setText(QString());
        label_8->setText(QString());
        label_9->setText(QString());
        label_10->setText(QString());
        label_11->setText(QString());
        label_12->setText(QString());
        label_13->setText(QString());
        label_14->setText(QString());
        label_15->setText(QString());
        label_16->setText(QString());
        label_17->setText(QString());
        label_18->setText(QString());
        label_19->setText(QString());
        label_20->setText(QString());
        label_21->setText(QString());
        label_22->setText(QString());
        label_23->setText(QString());
        label_24->setText(QString());
        label_25->setText(QString());
        label_26->setText(QString());
        label_27->setText(QString());
        label_28->setText(QString());
        label_29->setText(QString());
        label_30->setText(QString());
        label_31->setText(QString());
        label_32->setText(QString());
        label_33->setText(QString());
        label_34->setText(QString());
        label_35->setText(QString());
        label_36->setText(QString());
        label_37->setText(QString());
        label_38->setText(QString());
        label_39->setText(QString());
        label_40->setText(QString());
        label_41->setText(QString());
        label_42->setText(QString());
        label_43->setText(QString());
        label_44->setText(QString());
        label_45->setText(QString());
        label_46->setText(QString());
        label_47->setText(QString());
        label_48->setText(QString());
        label_49->setText(QString());
        label_50->setText(QString());
        label_51->setText(QString());
        label_52->setText(QString());
        label_53->setText(QString());
        label_54->setText(QString());
        label_55->setText(QString());
        label_56->setText(QString());
        label_57->setText(QString());
        label_58->setText(QString());
        label_59->setText(QString());
        label_60->setText(QString());
        menu->setTitle(QCoreApplication::translate("MainWindow", "Connect", nullptr));
        menuPlay->setTitle(QCoreApplication::translate("MainWindow", "Play", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
