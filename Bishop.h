//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_BISHOP_H
#define CHESSPROJECT3_BISHOP_H
#include "Piece.h"

class Bishop : public Piece{

public :

    vector<pair<int,int>>getAllMoves(int x, int y) override;

};

#endif //CHESSPROJECT3_BISHOP_H
