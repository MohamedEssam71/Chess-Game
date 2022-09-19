//
// Created by legion on 9/17/2022.
//
#include "Board.h"

Board :: Board(){

    pField = new Field**[8];

    for(int i = 0; i < 8; ++i){

        pField[i] = new Field*[8];

        for(int j = 0; j < 8; ++j){
            pField[i][j] = new Field();

            if(i == 0){
                if(j == 0 || j == 7){
                    pField[i][j]->setPiece(new Castle, BLACK, "BC");
                }
                if(j == 1 || j == 6){
                    pField[i][j]->setPiece(new Horse, BLACK, "BH");
                }
                if(j == 2 || j == 5){
                    pField[i][j]->setPiece(new Bishop, BLACK, "BB");
                }
                if(j == 3)
                    pField[i][j]->setPiece(new Queen, BLACK, "BQ");
                if(j == 4)
                    pField[i][j]->setPiece(new King, BLACK, "BK");
            }

            if(i == 7){
                if(j == 0 || j == 7){
                    pField[i][j]->setPiece(new Castle, WHITE, "WC");
                }
                if(j == 1 || j == 6){
                    pField[i][j]->setPiece(new Horse, WHITE, "WH");
                }
                if(j == 2 || j == 5){
                    pField[i][j]->setPiece(new Bishop, WHITE, "WB");
                }
                if(j == 3)
                    pField[i][j]->setPiece(new Queen, WHITE, "WQ");
                if(j == 4)
                    pField[i][j]->setPiece(new King, WHITE, "WK");
            }

            if(i == 1)
                pField[i][j]->setPiece(new Pawn, BLACK, "BP");

            if(i == 6)
                pField[i][j]->setPiece(new Pawn, WHITE, "WP");

            if(i > 1 && i < 6)
                pField[i][j]->setPiece(new Empty(), NONE, "EE");

        }
    }
}

Board :: ~Board(){
    for(int i = 0; i < 8; ++i){
        delete[] pField[i];
    }
    delete[] pField;
    pField = nullptr;
}

void Board :: swapPiece(pair<int,int> oldPosition, pair<int,int> newPosition){
    int oldX = oldPosition.first;
    int oldY = oldPosition.second;

    int newX = newPosition.first;
    int newY = newPosition.second;

    Piece* oldPiece = pField[oldX][oldY]->getPiece();
    Colors oldColor = pField[oldX][oldY]->getPiece()->getColor();
    string oldName = pField[oldX][oldY]->getPiece()->getIconName();

    Piece* newPiece = pField[newX][newY]->getPiece();
    Colors newColor = pField[newX][newY]->getPiece()->getColor();
    string newName = pField[newX][newY]->getPiece()->getIconName();

    if(newColor != oldColor || newColor == NONE){

        if(dynamic_cast<Empty*>(oldPiece))
            pField[newX][newY]->setPiece(new Empty(), NONE, oldName);

        if(dynamic_cast<Castle*>(oldPiece))
            pField[newX][newY]->setPiece(new Castle(), oldColor, oldName);

        if(dynamic_cast<Bishop*>(oldPiece))
            pField[newX][newY]->setPiece(new Bishop(), oldColor, oldName);

        if(dynamic_cast<Horse*>(oldPiece))
            pField[newX][newY]->setPiece(new Horse(), oldColor, oldName);

        if(dynamic_cast<Queen*>(oldPiece))
            pField[newX][newY]->setPiece(new Queen(), oldColor, oldName);

        if(dynamic_cast<King*>(oldPiece))
            pField[newX][newY]->setPiece(new King(), oldColor, oldName);

        if(dynamic_cast<Pawn*>(oldPiece))
            pField[newX][newY]->setPiece(new Pawn(), oldColor, oldName);

    }

    pField[oldX][oldY]->setPiece(new Empty(), NONE, "EE");

}

Field* Board :: getField(int x, int y){
    return pField[x][y];
}

bool Board :: isCheckMate(){
    int cntKing = 0;
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            if(dynamic_cast<King*>(getField(i,j)->getPiece()))
                cntKing++;
            if(cntKing == 2)
                return false;
        }
    }

    return true;
}