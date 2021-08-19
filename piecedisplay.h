#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include <QPixmap>

#include "piece.h"
#include "clickablelabel.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE

class PieceDisplay : public Piece
{
public:
    static void initDisplay(Ui::MainWindow *ui);

    void show(QPixmap *pix);
    void hide() override;
    void display() override;

private:
    static ClickableLabel *Label_Map[12][5];
    static QPixmap *Pixmap[50];

    static int w, h;

    static QPixmap *getPixmap(const char *path);
};

#endif // PIECEDISPLAY_H
