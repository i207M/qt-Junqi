#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>

#include "piece.h"

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

    PieceDisplay();
    ~PieceDisplay();

    void show() override;
    void hide() override;

private:
    static QLabel *Label_Map[12][5];
    static QPixmap Pixmap[26];

    static int w, h;

    static QPixmap getPixmap(const char *path);
};

#endif // PIECEDISPLAY_H
