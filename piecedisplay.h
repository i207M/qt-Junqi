#ifndef PIECEDISPLAY_H
#define PIECEDISPLAY_H

#include "piece.h"

class PieceDisplay : public Piece
{
public:
    static QLabel *Label_Map[12][5];
    static QPixmap *Pixmap[26];
    static void initDisplay();
    PieceDisplay();
    ~PieceDisplay();

    void show() override;
    void hide() override;
};

#endif // PIECEDISPLAY_H
