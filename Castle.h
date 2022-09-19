//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_CASTLE_H
#define CHESSPROJECT3_CASTLE_H
#include "Piece.h"



class Castle : public Piece{

public :

    vector<pair<int,int>>getAllMoves(int x, int y) override;

};

#endif //CHESSPROJECT3_CASTLE_H
