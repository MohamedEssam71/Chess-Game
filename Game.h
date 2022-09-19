//
// Created by legion on 9/17/2022.
//

#ifndef CHESSPROJECT3_GAME_H
#define CHESSPROJECT3_GAME_H
#include "Pawn.h"
#include "Empty.h"
#include "Castle.h"
#include "Bishop.h"
#include "Horse.h"
#include "Queen.h"
#include "King.h"
#include "Color.h"
#include "Board.h"

class Game{

private:

    Colors curColor;
    vector<pair<int,int>>pieceMoves;
    bool isGameOver = false;
    Board* board;

public:

    Game();

    ~Game();

    Colors getCurColor(int x, int y);

    void setCurColor(Colors curCol);


    vector<pair<int,int>> getPieceMoves();

    void setPieceMoves(vector<pair<int,int>>pieceMoves);

    bool getGameOver();

    void setGameOver();

    void endGame();

    Board* getBoard();

};

#endif //CHESSPROJECT3_GAME_H
