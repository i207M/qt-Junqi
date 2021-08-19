#ifndef CLICKABLELABEL_H
#define CLICKABLELABEL_H

#include <QLabel>
#include <QMouseEvent>

class ClickableLabel : public QLabel
{
    Q_OBJECT

public:
    explicit ClickableLabel(QWidget *parent = 0);

    int row, col;

protected:
    virtual void mousePressEvent(QMouseEvent *event);
};

#endif // CLICKABLELABEL_H
