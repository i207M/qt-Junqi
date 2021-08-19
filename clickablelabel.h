#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class Chessboard;

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = 0);

    static Chessboard *board;

    int row, col;

protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // CLICKABLELABEL_H
