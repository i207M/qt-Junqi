#include "piecedisplay.h"

#include <QImage>

#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "Mdebug.h"

ClickableLabel *PieceDisplay::Label_Map[12][5] = {};
QPixmap *PieceDisplay::Pixmap[50] = {};
int PieceDisplay::w = 0;
int PieceDisplay::h = 0;

void PieceDisplay::initDisplay(Ui::MainWindow *ui)
{
    // init Label_Map
    Label_Map[0][0] = ui->label1;
    Label_Map[0][0]->row = 0, Label_Map[0][0]->col = 0;
    Label_Map[0][1] = ui->label2;
    Label_Map[0][1]->row = 0, Label_Map[0][1]->col = 1;
    Label_Map[0][2] = ui->label3;
    Label_Map[0][2]->row = 0, Label_Map[0][2]->col = 2;
    Label_Map[0][3] = ui->label4;
    Label_Map[0][3]->row = 0, Label_Map[0][3]->col = 3;
    Label_Map[0][4] = ui->label5;
    Label_Map[0][4]->row = 0, Label_Map[0][4]->col = 4;
    Label_Map[1][0] = ui->label6;
    Label_Map[1][0]->row = 1, Label_Map[1][0]->col = 0;
    Label_Map[1][1] = ui->label7;
    Label_Map[1][1]->row = 1, Label_Map[1][1]->col = 1;
    Label_Map[1][2] = ui->label8;
    Label_Map[1][2]->row = 1, Label_Map[1][2]->col = 2;
    Label_Map[1][3] = ui->label9;
    Label_Map[1][3]->row = 1, Label_Map[1][3]->col = 3;
    Label_Map[1][4] = ui->label10;
    Label_Map[1][4]->row = 1, Label_Map[1][4]->col = 4;
    Label_Map[2][0] = ui->label11;
    Label_Map[2][0]->row = 2, Label_Map[2][0]->col = 0;
    Label_Map[2][1] = ui->label12;
    Label_Map[2][1]->row = 2, Label_Map[2][1]->col = 1;
    Label_Map[2][2] = ui->label13;
    Label_Map[2][2]->row = 2, Label_Map[2][2]->col = 2;
    Label_Map[2][3] = ui->label14;
    Label_Map[2][3]->row = 2, Label_Map[2][3]->col = 3;
    Label_Map[2][4] = ui->label15;
    Label_Map[2][4]->row = 2, Label_Map[2][4]->col = 4;
    Label_Map[3][0] = ui->label16;
    Label_Map[3][0]->row = 3, Label_Map[3][0]->col = 0;
    Label_Map[3][1] = ui->label17;
    Label_Map[3][1]->row = 3, Label_Map[3][1]->col = 1;
    Label_Map[3][2] = ui->label18;
    Label_Map[3][2]->row = 3, Label_Map[3][2]->col = 2;
    Label_Map[3][3] = ui->label19;
    Label_Map[3][3]->row = 3, Label_Map[3][3]->col = 3;
    Label_Map[3][4] = ui->label20;
    Label_Map[3][4]->row = 3, Label_Map[3][4]->col = 4;
    Label_Map[4][0] = ui->label21;
    Label_Map[4][0]->row = 4, Label_Map[4][0]->col = 0;
    Label_Map[4][1] = ui->label22;
    Label_Map[4][1]->row = 4, Label_Map[4][1]->col = 1;
    Label_Map[4][2] = ui->label23;
    Label_Map[4][2]->row = 4, Label_Map[4][2]->col = 2;
    Label_Map[4][3] = ui->label24;
    Label_Map[4][3]->row = 4, Label_Map[4][3]->col = 3;
    Label_Map[4][4] = ui->label25;
    Label_Map[4][4]->row = 4, Label_Map[4][4]->col = 4;
    Label_Map[5][0] = ui->label26;
    Label_Map[5][0]->row = 5, Label_Map[5][0]->col = 0;
    Label_Map[5][1] = ui->label27;
    Label_Map[5][1]->row = 5, Label_Map[5][1]->col = 1;
    Label_Map[5][2] = ui->label28;
    Label_Map[5][2]->row = 5, Label_Map[5][2]->col = 2;
    Label_Map[5][3] = ui->label29;
    Label_Map[5][3]->row = 5, Label_Map[5][3]->col = 3;
    Label_Map[5][4] = ui->label30;
    Label_Map[5][4]->row = 5, Label_Map[5][4]->col = 4;
    Label_Map[6][0] = ui->label31;
    Label_Map[6][0]->row = 6, Label_Map[6][0]->col = 0;
    Label_Map[6][1] = ui->label32;
    Label_Map[6][1]->row = 6, Label_Map[6][1]->col = 1;
    Label_Map[6][2] = ui->label33;
    Label_Map[6][2]->row = 6, Label_Map[6][2]->col = 2;
    Label_Map[6][3] = ui->label34;
    Label_Map[6][3]->row = 6, Label_Map[6][3]->col = 3;
    Label_Map[6][4] = ui->label35;
    Label_Map[6][4]->row = 6, Label_Map[6][4]->col = 4;
    Label_Map[7][0] = ui->label36;
    Label_Map[7][0]->row = 7, Label_Map[7][0]->col = 0;
    Label_Map[7][1] = ui->label37;
    Label_Map[7][1]->row = 7, Label_Map[7][1]->col = 1;
    Label_Map[7][2] = ui->label38;
    Label_Map[7][2]->row = 7, Label_Map[7][2]->col = 2;
    Label_Map[7][3] = ui->label39;
    Label_Map[7][3]->row = 7, Label_Map[7][3]->col = 3;
    Label_Map[7][4] = ui->label40;
    Label_Map[7][4]->row = 7, Label_Map[7][4]->col = 4;
    Label_Map[8][0] = ui->label41;
    Label_Map[8][0]->row = 8, Label_Map[8][0]->col = 0;
    Label_Map[8][1] = ui->label42;
    Label_Map[8][1]->row = 8, Label_Map[8][1]->col = 1;
    Label_Map[8][2] = ui->label43;
    Label_Map[8][2]->row = 8, Label_Map[8][2]->col = 2;
    Label_Map[8][3] = ui->label44;
    Label_Map[8][3]->row = 8, Label_Map[8][3]->col = 3;
    Label_Map[8][4] = ui->label45;
    Label_Map[8][4]->row = 8, Label_Map[8][4]->col = 4;
    Label_Map[9][0] = ui->label46;
    Label_Map[9][0]->row = 9, Label_Map[9][0]->col = 0;
    Label_Map[9][1] = ui->label47;
    Label_Map[9][1]->row = 9, Label_Map[9][1]->col = 1;
    Label_Map[9][2] = ui->label48;
    Label_Map[9][2]->row = 9, Label_Map[9][2]->col = 2;
    Label_Map[9][3] = ui->label49;
    Label_Map[9][3]->row = 9, Label_Map[9][3]->col = 3;
    Label_Map[9][4] = ui->label50;
    Label_Map[9][4]->row = 9, Label_Map[9][4]->col = 4;
    Label_Map[10][0] = ui->label51;
    Label_Map[10][0]->row = 10, Label_Map[10][0]->col = 0;
    Label_Map[10][1] = ui->label52;
    Label_Map[10][1]->row = 10, Label_Map[10][1]->col = 1;
    Label_Map[10][2] = ui->label53;
    Label_Map[10][2]->row = 10, Label_Map[10][2]->col = 2;
    Label_Map[10][3] = ui->label54;
    Label_Map[10][3]->row = 10, Label_Map[10][3]->col = 3;
    Label_Map[10][4] = ui->label55;
    Label_Map[10][4]->row = 10, Label_Map[10][4]->col = 4;
    Label_Map[11][0] = ui->label56;
    Label_Map[11][0]->row = 11, Label_Map[11][0]->col = 0;
    Label_Map[11][1] = ui->label57;
    Label_Map[11][1]->row = 11, Label_Map[11][1]->col = 1;
    Label_Map[11][2] = ui->label58;
    Label_Map[11][2]->row = 11, Label_Map[11][2]->col = 2;
    Label_Map[11][3] = ui->label59;
    Label_Map[11][3]->row = 11, Label_Map[11][3]->col = 3;
    Label_Map[11][4] = ui->label60;
    Label_Map[11][4]->row = 11, Label_Map[11][4]->col = 4;

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

    Pixmap[24 + 0] = getPixmap(":/piece/images/border_gongbing_red.png");
    Pixmap[24 + 1] = getPixmap(":/piece/images/border_paizhang_red.png");
    Pixmap[24 + 2] = getPixmap(":/piece/images/border_lianzhang_red.png");
    Pixmap[24 + 3] = getPixmap(":/piece/images/border_yingzhang_red.png");
    Pixmap[24 + 4] = getPixmap(":/piece/images/border_tuanzhang_red.png");
    Pixmap[24 + 5] = getPixmap(":/piece/images/border_lvzhang_red.png");
    Pixmap[24 + 6] = getPixmap(":/piece/images/border_shizhang_red.png");
    Pixmap[24 + 7] = getPixmap(":/piece/images/border_junzhang_red.png");
    Pixmap[24 + 8] = getPixmap(":/piece/images/border_siling_red.png");
    Pixmap[24 + 9] = getPixmap(":/piece/images/border_zhadan_red.png");
    Pixmap[24 + 10] = getPixmap(":/piece/images/border_dilei_red.png");
    Pixmap[24 + 11] = getPixmap(":/piece/images/border_junqi_red.png");

    Pixmap[24 + 12 + 0] = getPixmap(":/piece/images/border_gongbing_blue.png");
    Pixmap[24 + 12 + 1] = getPixmap(":/piece/images/border_paizhang_blue.png");
    Pixmap[24 + 12 + 2] = getPixmap(":/piece/images/border_lianzhang_blue.png");
    Pixmap[24 + 12 + 3] = getPixmap(":/piece/images/border_yingzhang_blue.png");
    Pixmap[24 + 12 + 4] = getPixmap(":/piece/images/border_tuanzhang_blue.png");
    Pixmap[24 + 12 + 5] = getPixmap(":/piece/images/border_lvzhang_blue.png");
    Pixmap[24 + 12 + 6] = getPixmap(":/piece/images/border_shizhang_blue.png");
    Pixmap[24 + 12 + 7] = getPixmap(":/piece/images/border_junzhang_blue.png");
    Pixmap[24 + 12 + 8] = getPixmap(":/piece/images/border_siling_blue.png");
    Pixmap[24 + 12 + 9] = getPixmap(":/piece/images/border_zhadan_blue.png");
    Pixmap[24 + 12 + 10] = getPixmap(":/piece/images/border_dilei_blue.png");
    Pixmap[24 + 12 + 11] = getPixmap(":/piece/images/border_junqi_blue.png");

    Pixmap[48] = getPixmap(":/piece/images/unknown.png");
    QPixmap *pix = new QPixmap(w, h);
    pix->fill(Qt::transparent);
    Pixmap[49] = pix;
}

void PieceDisplay::show(QPixmap *pix)
{
    ClickableLabel *label = Label_Map[row][col];
    label->setPixmap(*pix);
}

void PieceDisplay::hide()
{
    ClickableLabel *label = Label_Map[row][col];
    label->setPixmap(*Pixmap[49]);
}

bool PieceDisplay::showSelected()
{
    if(id == board->select_id) {
        if(not board->is_online) {
            return true;
        } else {
            int local_color = board->current_color;
            if((1 + board->is_server) != board->current_player) {
                local_color = (local_color == 1 ? 2 : 1);
            }
            return color == local_color;
        }
    }
}

void PieceDisplay::display()
{
    if(dead) {
        hide();
    } else if (not known) {
        show(Pixmap[48]);
    } else {
        show(Pixmap[(showSelected() ? 24 : 0) + (color == 1 ? 0 : 12) + int(type)]);
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
