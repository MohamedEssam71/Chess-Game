//
// Created by legion on 9/17/2022.
//
#include "Horse.h"

vector<pair<int,int>>Horse :: getAllMoves(int x, int y){
    moves.clear();

    int dir[] = {-2,-1,1,2};


    for(int i : dir) {
        for (int j: dir) {
            if (abs(i) != abs(j)) {
                int newX = x - i;
                int newY = y - j;
                if ((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8)) {
                    pair<int, int> newPosition(newX, newY);
                    moves.push_back(newPosition);
                }
            }
        }
    }

    return moves;
}
