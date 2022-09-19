#include "Piece.h"
#include "game.h"
extern Game *game;

Piece :: Piece() {
}

Piece :: ~Piece(){

}

void Piece :: setColor(Colors c){
    color = c;
}

Colors Piece :: getColor(){
    return color;
}


string Piece ::  getIconName(){
    return iconName;
}

void  Piece :: setIconName(string iN){
    iconName = std::move(iN);
}

vector<pair<int,int>> Piece :: getAllMoves(int x, int y){
    return {};
}

bool Piece :: isOpponent(pair<int,int> PositionTo, pair<int,int>source){
    Colors c = game->getBoard()->getField(PositionTo.first, PositionTo.second)->getPiece()->getColor();
    Colors c2 = game->getBoard()->getField(source.first,source.second)->getPiece()->getColor();
    if(c != c2 && c != NONE){
        return true;
    }
    return false;
}

bool Piece :: isEmpty(pair<int,int> PositionTo){
    if(dynamic_cast<Empty*>(game->getBoard()->getField(PositionTo.first, PositionTo.second)->getPiece()))
        return true;
    return false;
}



// Created by legion on 9/17/2022.
//
