//
// Created by legion on 9/17/2022.
//
#include "Field.h"


Field :: Field() {

}

Field :: ~Field() {

}

void Field :: setPiece(Piece* p, Colors color, string iconName){
    chessPiece = p;
    chessPiece->setColor(color);
    chessPiece->setIconName(std::move(iconName));

}

Piece* Field ::  getPiece(){
    return chessPiece;
}

vector<pair<int,int>> Field :: getMoves(int x, int y){
    return chessPiece->getAllMoves(x,y);
}

