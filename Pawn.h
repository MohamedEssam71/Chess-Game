//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_PAWN_H
#define CHESSPROJECT3_PAWN_H
#include "Piece.h"

class Pawn : public Piece{

public:

    vector<pair<int,int>> getAllMoves(int x, int y) override;

};


#endif //CHESSPROJECT3_PAWN_H
