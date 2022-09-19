//
// Created by legion on 9/17/2022.
//
#include "Game.h"

Game :: Game(){
    board = new Board();
    curColor;
}

Game :: ~Game(){

}

Colors Game ::  getCurColor(int x, int y){
    return getBoard()->getField(x,y)->getPiece()->getColor();
}

void Game ::  setCurColor(Colors curCol){
    this->curColor = (curCol == BLACK ? WHITE : BLACK);
}

vector<pair<int,int>> Game ::  getPieceMoves(){
    return pieceMoves;
}

void Game :: setPieceMoves(vector<pair<int,int>>pieceMoves){
    this->pieceMoves = pieceMoves;
}

bool Game :: getGameOver(){
    return isGameOver;
}


void Game :: setGameOver(){
    this->isGameOver = board->isCheckMate();
}

void Game :: endGame(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            board->getField(i,j)->setPiece(new Empty, NONE, "EE");
        }
    }
}

Board* Game :: getBoard(){
    return this->board;
}


