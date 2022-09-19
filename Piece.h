//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_PIECE_H
#define CHESSPROJECT3_PIECE_H
#include <bits/stdc++.h>
#include "Color.h"
using namespace std;

class Piece{

private:

    Colors color;
    string iconName;

protected:

    vector<pair<int,int>> moves;

public:
    Piece();

    ~Piece();

    void setColor(Colors c);

    Colors getColor();

    string getIconName();

    void setIconName(string iN);

    virtual vector<pair<int,int>> getAllMoves(int x, int y);

    static bool isOpponent(pair<int,int> PositionTo, pair<int,int>Source);

    static bool isEmpty(pair<int,int> PositionTo);

};





#endif //CHESSPROJECT3_PIECE_H
