#include <QImage>

#include "piecedisplay.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Mdebug.h"

QLabel *PieceDisplay::Label_Map[12][5] = {};
QPixmap *PieceDisplay::Pixmap[50] = {};
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
    PieceDisplay::Label_Map[0][0] = ui->label1;
    PieceDisplay::Label_Map[0][1] = ui->label2;
    PieceDisplay::Label_Map[0][2] = ui->label3;
    PieceDisplay::Label_Map[0][3] = ui->label4;
    PieceDisplay::Label_Map[0][4] = ui->label5;
    PieceDisplay::Label_Map[1][0] = ui->label6;
    PieceDisplay::Label_Map[1][1] = ui->label7;
    PieceDisplay::Label_Map[1][2] = ui->label8;
    PieceDisplay::Label_Map[1][3] = ui->label9;
    PieceDisplay::Label_Map[1][4] = ui->label10;
    PieceDisplay::Label_Map[2][0] = ui->label11;
    PieceDisplay::Label_Map[2][1] = ui->label12;
    PieceDisplay::Label_Map[2][2] = ui->label13;
    PieceDisplay::Label_Map[2][3] = ui->label14;
    PieceDisplay::Label_Map[2][4] = ui->label15;
    PieceDisplay::Label_Map[3][0] = ui->label16;
    PieceDisplay::Label_Map[3][1] = ui->label17;
    PieceDisplay::Label_Map[3][2] = ui->label18;
    PieceDisplay::Label_Map[3][3] = ui->label19;
    PieceDisplay::Label_Map[3][4] = ui->label20;
    PieceDisplay::Label_Map[4][0] = ui->label21;
    PieceDisplay::Label_Map[4][1] = ui->label22;
    PieceDisplay::Label_Map[4][2] = ui->label23;
    PieceDisplay::Label_Map[4][3] = ui->label24;
    PieceDisplay::Label_Map[4][4] = ui->label25;
    PieceDisplay::Label_Map[5][0] = ui->label26;
    PieceDisplay::Label_Map[5][1] = ui->label27;
    PieceDisplay::Label_Map[5][2] = ui->label28;
    PieceDisplay::Label_Map[5][3] = ui->label29;
    PieceDisplay::Label_Map[5][4] = ui->label30;
    PieceDisplay::Label_Map[6][0] = ui->label31;
    PieceDisplay::Label_Map[6][1] = ui->label32;
    PieceDisplay::Label_Map[6][2] = ui->label33;
    PieceDisplay::Label_Map[6][3] = ui->label34;
    PieceDisplay::Label_Map[6][4] = ui->label35;
    PieceDisplay::Label_Map[7][0] = ui->label36;
    PieceDisplay::Label_Map[7][1] = ui->label37;
    PieceDisplay::Label_Map[7][2] = ui->label38;
    PieceDisplay::Label_Map[7][3] = ui->label39;
    PieceDisplay::Label_Map[7][4] = ui->label40;
    PieceDisplay::Label_Map[8][0] = ui->label41;
    PieceDisplay::Label_Map[8][1] = ui->label42;
    PieceDisplay::Label_Map[8][2] = ui->label43;
    PieceDisplay::Label_Map[8][3] = ui->label44;
    PieceDisplay::Label_Map[8][4] = ui->label45;
    PieceDisplay::Label_Map[9][0] = ui->label46;
    PieceDisplay::Label_Map[9][1] = ui->label47;
    PieceDisplay::Label_Map[9][2] = ui->label48;
    PieceDisplay::Label_Map[9][3] = ui->label49;
    PieceDisplay::Label_Map[9][4] = ui->label50;
    PieceDisplay::Label_Map[10][0] = ui->label51;
    PieceDisplay::Label_Map[10][1] = ui->label52;
    PieceDisplay::Label_Map[10][2] = ui->label53;
    PieceDisplay::Label_Map[10][3] = ui->label54;
    PieceDisplay::Label_Map[10][4] = ui->label55;
    PieceDisplay::Label_Map[11][0] = ui->label56;
    PieceDisplay::Label_Map[11][1] = ui->label57;
    PieceDisplay::Label_Map[11][2] = ui->label58;
    PieceDisplay::Label_Map[11][3] = ui->label59;
    PieceDisplay::Label_Map[11][4] = ui->label60;

    // init Pixmap
    w = Label_Map[0][0]->width();
    h = Label_Map[0][0]->height();

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
}

void PieceDisplay::show(QPixmap *pix)
{
    QLabel *label = Label_Map[row][col];
    label->setPixmap(*pix);
}

void PieceDisplay::hide()
{
    QLabel *label = Label_Map[row][col];
    label->setPixmap(*Pixmap[49]);
}

void PieceDisplay::display()
{
    if(dead) {
        hide();
    } else if (not known) {
        show(Pixmap[48]);
    } else {
        show(Pixmap[(team == 1 ? 0 : 12) + (selected ? 24 : 0) + int(type)]);
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
