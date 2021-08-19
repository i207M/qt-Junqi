#include <iostream>
using std::cerr;

#include <QImage>

#include "piecedisplay.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

QLabel *PieceDisplay::Label_Map[12][5] = {};
QPixmap *PieceDisplay::Pixmap[26] = {};
int PieceDisplay::w = 0;
int PieceDisplay::h = 0;

PieceDisplay::PieceDisplay()
{
    ;
}

PieceDisplay::~PieceDisplay()
{
    ;
}

void PieceDisplay::initDisplay(Ui::MainWindow *ui)
{
    // init Label_Map
    #pragma region
    PieceDisplay::Label_Map[0][0] = ui->label_1;
    PieceDisplay::Label_Map[0][1] = ui->label_2;
    PieceDisplay::Label_Map[0][2] = ui->label_3;
    PieceDisplay::Label_Map[0][3] = ui->label_4;
    PieceDisplay::Label_Map[0][4] = ui->label_5;
    PieceDisplay::Label_Map[1][0] = ui->label_6;
    PieceDisplay::Label_Map[1][1] = ui->label_7;
    PieceDisplay::Label_Map[1][2] = ui->label_8;
    PieceDisplay::Label_Map[1][3] = ui->label_9;
    PieceDisplay::Label_Map[1][4] = ui->label_10;
    PieceDisplay::Label_Map[2][0] = ui->label_11;
    PieceDisplay::Label_Map[2][1] = ui->label_12;
    PieceDisplay::Label_Map[2][2] = ui->label_13;
    PieceDisplay::Label_Map[2][3] = ui->label_14;
    PieceDisplay::Label_Map[2][4] = ui->label_15;
    PieceDisplay::Label_Map[3][0] = ui->label_16;
    PieceDisplay::Label_Map[3][1] = ui->label_17;
    PieceDisplay::Label_Map[3][2] = ui->label_18;
    PieceDisplay::Label_Map[3][3] = ui->label_19;
    PieceDisplay::Label_Map[3][4] = ui->label_20;
    PieceDisplay::Label_Map[4][0] = ui->label_21;
    PieceDisplay::Label_Map[4][1] = ui->label_22;
    PieceDisplay::Label_Map[4][2] = ui->label_23;
    PieceDisplay::Label_Map[4][3] = ui->label_24;
    PieceDisplay::Label_Map[4][4] = ui->label_25;
    PieceDisplay::Label_Map[5][0] = ui->label_26;
    PieceDisplay::Label_Map[5][1] = ui->label_27;
    PieceDisplay::Label_Map[5][2] = ui->label_28;
    PieceDisplay::Label_Map[5][3] = ui->label_29;
    PieceDisplay::Label_Map[5][4] = ui->label_30;
    PieceDisplay::Label_Map[6][0] = ui->label_31;
    PieceDisplay::Label_Map[6][1] = ui->label_32;
    PieceDisplay::Label_Map[6][2] = ui->label_33;
    PieceDisplay::Label_Map[6][3] = ui->label_34;
    PieceDisplay::Label_Map[6][4] = ui->label_35;
    PieceDisplay::Label_Map[7][0] = ui->label_36;
    PieceDisplay::Label_Map[7][1] = ui->label_37;
    PieceDisplay::Label_Map[7][2] = ui->label_38;
    PieceDisplay::Label_Map[7][3] = ui->label_39;
    PieceDisplay::Label_Map[7][4] = ui->label_40;
    PieceDisplay::Label_Map[8][0] = ui->label_41;
    PieceDisplay::Label_Map[8][1] = ui->label_42;
    PieceDisplay::Label_Map[8][2] = ui->label_43;
    PieceDisplay::Label_Map[8][3] = ui->label_44;
    PieceDisplay::Label_Map[8][4] = ui->label_45;
    PieceDisplay::Label_Map[9][0] = ui->label_46;
    PieceDisplay::Label_Map[9][1] = ui->label_47;
    PieceDisplay::Label_Map[9][2] = ui->label_48;
    PieceDisplay::Label_Map[9][3] = ui->label_49;
    PieceDisplay::Label_Map[9][4] = ui->label_50;
    PieceDisplay::Label_Map[10][0] = ui->label_51;
    PieceDisplay::Label_Map[10][1] = ui->label_52;
    PieceDisplay::Label_Map[10][2] = ui->label_53;
    PieceDisplay::Label_Map[10][3] = ui->label_54;
    PieceDisplay::Label_Map[10][4] = ui->label_55;
    PieceDisplay::Label_Map[11][0] = ui->label_56;
    PieceDisplay::Label_Map[11][1] = ui->label_57;
    PieceDisplay::Label_Map[11][2] = ui->label_58;
    PieceDisplay::Label_Map[11][3] = ui->label_59;
    PieceDisplay::Label_Map[11][4] = ui->label_60;
    #pragma endregion
    // init Pixmap
    w = Label_Map[0][0]->width();
    h = Label_Map[0][0]->height();
    #pragma region
    Pixmap[0] = getPixmap(":/piece/images/gongbing_red.png");
    Pixmap[1] = getPixmap(":/piece/images/paizhang_red.png");
    Pixmap[2] = getPixmap(":/piece/images/lianzhang_red.png");
    Pixmap[3] = getPixmap(":/piece/images/yingzhang_red.png");
    Pixmap[4] = getPixmap(":/piece/images/tuanzhang_red.png");
    Pixmap[5] = getPixmap(":/piece/images/lvzhang_red.png");
    Pixmap[6] = getPixmap(":/piece/images/shizhang_red.png");
    Pixmap[7] = getPixmap(":/piece/images/junzhang_red.png");
    Pixmap[8] = getPixmap(":/piece/images/siling_red.png");
    Pixmap[9] = getPixmap(":/piece/images/zhadan_red.png");
    Pixmap[10] = getPixmap(":/piece/images/dilei_red.png");
    Pixmap[11] = getPixmap(":/piece/images/junqi_red.png");

    Pixmap[12 + 0] = getPixmap(":/piece/images/gongbing_blue.png");
    Pixmap[12 + 1] = getPixmap(":/piece/images/paizhang_blue.png");
    Pixmap[12 + 2] = getPixmap(":/piece/images/lianzhang_blue.png");
    Pixmap[12 + 3] = getPixmap(":/piece/images/yingzhang_blue.png");
    Pixmap[12 + 4] = getPixmap(":/piece/images/tuanzhang_blue.png");
    Pixmap[12 + 5] = getPixmap(":/piece/images/lvzhang_blue.png");
    Pixmap[12 + 6] = getPixmap(":/piece/images/shizhang_blue.png");
    Pixmap[12 + 7] = getPixmap(":/piece/images/junzhang_blue.png");
    Pixmap[12 + 8] = getPixmap(":/piece/images/siling_blue.png");
    Pixmap[12 + 9] = getPixmap(":/piece/images/zhadan_blue.png");
    Pixmap[12 + 10] = getPixmap(":/piece/images/dilei_blue.png");
    Pixmap[12 + 11] = getPixmap(":/piece/images/junqi_blue.png");

    Pixmap[24] = getPixmap(":/piece/images/unknown.png");
    QPixmap *pix = new QPixmap(w, h);
    pix->fill(Qt::transparent);
    Pixmap[25] = pix;
    #pragma endregion
}

void PieceDisplay::show(QPixmap *pix)
{
    QLabel *label = Label_Map[row][col];
    label->setPixmap(*pix);
}

void PieceDisplay::hide()
{
    ;
}

void PieceDisplay::display()
{
    if(dead) {
        return;
    } else if (not known) {
        show(Pixmap[24]);
    }
}

QPixmap *PieceDisplay::getPixmap(const char *path)
{
    QImage img;
    img.load(path);
    QPixmap pix = QPixmap::fromImage(img);
    pix = pix.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    QPixmap *ret = new QPixmap(pix);
    return ret;
}
