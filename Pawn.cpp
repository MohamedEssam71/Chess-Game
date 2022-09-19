//
// Created by legion on 9/17/2022.
//
#include "Pawn.h"
#include "Game.h"
extern Game* game;

vector<pair<int,int>> Pawn ::getAllMoves(int x, int y){
    moves.clear();
    int dir[] = {-1,0,1};

    if(game->getBoard()->getField(x,y)->getPiece()->getColor() == BLACK){
        for (int i : dir) {
            int newX = x + 1;
            int newY = y + i;
            if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8)){
                pair<int,int>newPosition(newX, newY);
                if((isOpponent(newPosition, {x,y}) && newY != y) || (isEmpty(newPosition) && newY == y))
                    moves.push_back(newPosition);
            }
            if(x == 1){
                pair<int,int>newPosition(3,y);
                if(isEmpty(newPosition))
                    moves.push_back(newPosition);
            }
        }
    }
    else{
        for (int i : dir) {
            int newX = x - 1;
            int newY = y + i;
            if((newX >= 0 && newX < 8) && (newY >= 0 && newY < 8)){
                pair<int,int>newPosition(newX, newY);
                if((isOpponent(newPosition, {x,y}) && newY != y) || (isEmpty(newPosition) && newY == y))
                    moves.push_back(newPosition);
            }
            if(x == 6){
                pair<int,int>newPosition(4,y);
                if(isEmpty(newPosition))
                    moves.push_back(newPosition);
            }
        }
    }
    return moves;
}
