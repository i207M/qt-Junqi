#include "piece.h"

#include "Mdebug.h"

Chessboard *Piece::board = nullptr;

void Piece::initPiece(int _team, Type _type)
{
    team = _team, type = _type;
    known = false, dead = false, selected = false;
}

void Piece::flip()
{
    if(known) {
        err("Warning: Trying to flip known piece.");
    } else {
        known = true;
    }
}

void Piece::select(bool flag)
{
    selected = flag;
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
