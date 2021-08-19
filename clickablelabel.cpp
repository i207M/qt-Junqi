#include "clickablelabel.h"

#include "chessboard.h"
#include "Mdebug.h"

Chessboard *ClickableLabel::board = nullptr;

ClickableLabel::ClickableLabel(QWidget *parent): QLabel(parent)
{
    row = -1, col = -1;
}

void ClickableLabel::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        board->clickPos(row, col);
    }
}
