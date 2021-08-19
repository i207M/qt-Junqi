#include "piece.h"

#include "Mdebug.h"

Chessboard *Piece::board = nullptr;

void Piece::initPiece(int _id, int _team, Type _type)
{
    id = _id, color = _team, type = _type;
    known = false, dead = false;
}

void Piece::flip()
{
    known = true;
}

void Piece::kill()
{
    dead = true;
}

void Piece::move(int _row, int _col)
{
    row = _row, col = _col;
}

bool Piece::canMove(int row, int obj)
{
    ;
}

bool Piece::tryAttack(Piece &obj)
{
    ;
}
