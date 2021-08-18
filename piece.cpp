#include "piece.h"

void Piece::display()
{
    if(dead) {
        return;
    }
    if (not known) {
        QImage image;
        image.load(":/piece/images/unknown.png");
        QPixmap pixmap = QPixmap::fromImage(image);
        QLabel *label = label_map[row][col];
        int w = label->width();
        int h = label->height();

        QPixmap fixpixmap = pixmap.scaled(w, h, Qt::IgnoreAspectRatio, Qt::SmoothTransformation);
        label->setPixmap(fixpixmap);
    }
}
