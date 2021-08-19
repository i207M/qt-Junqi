#include "piecedisplay.h"

QLabel *PieceDisplay::Label_Map[12][5] = {};
QPixmap *PieceDisplay::Pixmap[26] = {};

PieceDisplay::PieceDisplay()
{
    ;
}

PieceDisplay::~PieceDisplay()
{
    ;
}

void PieceDisplay::initDisplay()
{
    ;
}

void PieceDisplay::show()
{
    QImage image;
    image.load(":/piece/images/unknown.png");
    QPixmap pixmap = QPixmap::fromImage(image);
    QLabel *label = Label_Map[row][col];
    int w = label->width();
    int h = label->height();

    QPixmap fixpixmap = pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
    label->setPixmap(fixpixmap);
}

void PieceDisplay::hide()
{
    ;
}
