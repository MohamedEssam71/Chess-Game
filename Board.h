//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_BOARD_H
#define CHESSPROJECT3_BOARD_H
#include "Field.h"
#include "Piece.h"
#include "Empty.h"
#include "Bishop.h"
#include "Castle.h"
#include "Color.h"
#include "King.h"
#include "Queen.h"
#include "Horse.h"
#include "Pawn.h"


class Board{

private :

Field *** pField;

public:

Board();

~Board();

void swapPiece(pair<int,int> oldPosition, pair<int,int> newPosition);

Field* getField(int x, int y);

bool isCheckMate();

};



#endif //CHESSPROJECT3_BOARD_H
