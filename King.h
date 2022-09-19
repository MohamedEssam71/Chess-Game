//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_KING_H
#define CHESSPROJECT3_KING_H
#include "Piece.h"

class King : public Piece{

public:

    vector<pair<int,int>>getAllMoves(int x, int y) override;

};
#endif //CHESSPROJECT3_KING_H
