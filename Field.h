//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_FIELD_H
#define CHESSPROJECT3_FIELD_H
#include "Piece.h"

class Field{

private:

    Piece* chessPiece;

public:

    Field();

    ~Field();

    void setPiece(Piece* p, Colors color, string iconName);

    Piece* getPiece();

    vector<pair<int,int>> getMoves(int x, int y);

};


#endif //CHESSPROJECT3_FIELD_H
