//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_EMPTY_H
#define CHESSPROJECT3_EMPTY_H
#include "Piece.h"

class Empty : public Piece{

public :

    vector<pair<int,int>>getAllMoves(int x, int y) override;

};

#endif //CHESSPROJECT3_EMPTY_H
