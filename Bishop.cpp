//
// Created by legion on 9/17/2022.
//
#include "Bishop.h"

vector<pair<int,int>> Bishop ::getAllMoves(int x, int y){
    moves.clear();
    int dir[] = {1,2,3,4,5,6,7};

    bool f1, f2, f3, f4;
    f1 = f2 = f3 = f4 = true;

    for(int i : dir){
        int newX = x + i;
        int newY = y + i;

        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f1) {

            pair<int, int> newPosition(newX, newY);

            if (isOpponent(newPosition, {x,y}) || isEmpty(newPosition))
                moves.push_back(newPosition);
            else
                f1 = false;
            if(isOpponent(newPosition, {x,y}))
                f1 = false;

        }

        newX = x - i;
        newY = y - i;

        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f2) {

            pair<int, int> newPosition(newX, newY);

            if (isOpponent(newPosition, {x,y}) || isEmpty(newPosition))
                moves.push_back(newPosition);
            else
                f2 = false;
            if(isOpponent(newPosition, {x,y}))
                f2 = false;

        }

        newX = x + i;
        newY = y - i;

        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f3) {

            pair<int, int> newPosition(newX, newY);

            if (isOpponent(newPosition, {x,y}) || isEmpty(newPosition))
                moves.push_back(newPosition);
            else
                f3 = false;
            if(isOpponent(newPosition, {x,y}))
                f3 = false;

        }

        newX = x - i;
        newY = y + i;

        if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8) && f4) {

            pair<int, int> newPosition(newX, newY);

            if (isOpponent(newPosition, {x,y}) || isEmpty(newPosition))
                moves.push_back(newPosition);
            else
                f4 = false;
            if(isOpponent(newPosition, {x,y}))
                f4 = false;

        }

    }
    return moves;
}
