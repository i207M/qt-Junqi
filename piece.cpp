#include "piece.h"

void Piece::init(int _team, Type _type)
{
    team = _team, type = _type;
    known = false, dead = false, selected = false;
}

void Piece::flip()
{
    ;
}
