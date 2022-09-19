//
// Created by legion on 9/17/2022.
//
#include "King.h"

vector<pair<int,int>>King :: getAllMoves(int x, int y){
    moves.clear();

    int dir[] = {1,0,-1};

    for(int i : dir){
        for(int j : dir) {

            int newX = x + i;
            int newY = y + j;

            pair<int, int> newPosition(newX, newY);

            if ((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8))
                moves.push_back(newPosition);

        }
    }
    return moves;
}
