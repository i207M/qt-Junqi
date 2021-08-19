#include "clickablelabel.h"

#include "Mdebug.h"

ClickableLabel::ClickableLabel(QWidget *parent): QLabel(parent) {}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        err(row, col);
    }
}
