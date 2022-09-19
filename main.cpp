#include <bits/stdc++.h>
#include "Game.h"
#include<fcntl.h>
#include<io.h>

using namespace std;
Game* game;

class MainGame : public Game{

public:
    static void fillBoard();
    static set<pair<int,int>> CheckMoves(set<pair<int,int>>&mov, Colors col);
    static bool inCheck(Colors colorCheck);
    static pair<int,int> findKingPosition(Colors kingColor);
    static set<pair<int,int>> CheckKingMoves(int x, int y, Colors kingColor);
    static void printMoves(set<pair<int,int>>& mov);
    void PlayerTurn(int num, bool& error, Colors col);
    static Colors checkWinner();
    static void ChooseColor(Colors& player1, Colors& player2);
    static void PawnChange(Piece *pawnCheck, int x, int y, int newX);
};


void MainGame :: fillBoard(){
    _setmode(_fileno(stdout), _O_WTEXT);
    wcout << endl;
    wcout <<setw(2) << " ";
    for(int i = 0; i < 8; ++i) {
        if(i >= 4 && i < 6)wcout << " ";
        wcout << setw(6) << i + 1;
    }
    wcout << endl << endl;


    for (int i = 0; i < 8; ++i){
        wcout << setw(0) << i + 1 << setw(0) << "  ";// << L" \u2502";

        for (int j = 0; j < 8; ++j){
                if(j >= 3) wcout << " ";
            string x = game->getBoard()->getField(i,j)->getPiece()->getIconName();
            char a = x[0], b = x[1];
            switch(b) {
                case 'P':
                    wcout << setw(5) << (a == 'B' ? L"\u2659" : L"\u265F");
                    break;
                case 'K':
                    wcout << setw(5) << (a == 'B' ? L"\u2654" : L"\u265A");
                    break;
                case 'Q':
                    wcout << setw(5) << (a == 'B' ? L"\u2655" : L"\u265B");
                    break;
                case 'H':
                    wcout << setw(5) << (a == 'B' ? L"\u2658" : L"\u265E");
                    break;
                case 'C':
                    wcout << setw(5) << (a == 'B' ? L"\u2656" : L"\u265C");
                    break;
                case 'B':
                    wcout << setw(5) << (a == 'B' ? L"\u2657" : L"\u265D");
                    break;
                case 'E' :
                    wcout << setw(5) << L"\u235F";
                    if(j == 1 || j == 4)wcout <<" ";
                    break;
            }

        }
        wcout << endl << endl;
    }
}


set<pair<int,int>> MainGame :: CheckMoves(set<pair<int,int>>&mov, Colors col){
    set<pair<int,int>>moves;
    for(auto pair : mov){
        Colors curColor = game->getBoard()->getField(pair.first,pair.second)->getPiece()->getColor();
        if(curColor != col){
            moves.insert(pair);
        }
    }
    return moves;
}


ostream& operator <<(ostream& out, vector<pair<int,int>>mov2){
    out << "Available Moves to Play : " << endl;
    out << "[ ";
    for(int i = 0; i < mov2.size()-1; ++i){
        out << "(" << mov2[i].first << ", " << mov2[i].second << "), ";
    }
    out << "(" << mov2[mov2.size()-1].first << ", " << mov2[mov2.size()-1].second << ") ]";

    return out;
}


bool MainGame :: inCheck(Colors colorCheck){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            Piece* ptrP = game->getBoard()->getField(i,j)->getPiece();
            if(ptrP->getColor() != colorCheck && ptrP->getColor() != NONE){
                vector<pair<int,int>>checkMov = ptrP->getAllMoves(i,j);
                for(auto pair : checkMov){
                    Piece* KingCheck = game->getBoard()->getField(pair.first, pair.second)->getPiece();
                    if(dynamic_cast<King*>(KingCheck)){
                        if(KingCheck->getColor() == colorCheck){
                            return true;

                        }
                    }
                }
            }
        }
    }
    return false;
}


pair<int,int> MainGame :: findKingPosition(Colors kingColor){
    for(int i = 0; i < 8; ++i){
        for(int j = 0; j < 8; ++j){
            Piece* ptrP = game->getBoard()->getField(i,j)->getPiece();
            if(dynamic_cast<King*>(ptrP)){
                if(ptrP->getColor() == kingColor){
                    return {i,j};
                }
            }
        }
    }
}


set<pair<int,int>> MainGame :: CheckKingMoves(int x, int y, Colors kingColor){

    set<pair<int,int>>allKingMoves;
    for(auto dest : game->getBoard()->getField(x,y)->getPiece()->getAllMoves(x,y)){
        allKingMoves.insert(dest);
    }

    set<pair<int,int>>validKingMoves = CheckMoves(allKingMoves,kingColor);

    set<pair<int,int>>protectedKingMoves;

        for(auto dest : validKingMoves){
            bool danger = false;
            for(int i = 0; i < 8; ++i){
                for(int j = 0; j < 8; ++j){
                    Piece* ptrP = game->getBoard()->getField(i,j)->getPiece();
                    if(ptrP->getColor() != kingColor){
                        vector<pair<int,int>>checkMov = ptrP->getAllMoves(i,j);
                        for(auto pair : checkMov){
                            if(pair == dest){
                                    danger = true;
                                    break;
                                }
                            }
                    }
                }
                if(danger) break;
            }
            if(!danger){
                protectedKingMoves.insert(dest);
            }
        }
        return protectedKingMoves;
}


void MainGame :: printMoves(set<pair<int,int>>& mov){
    _setmode(_fileno(stdout), _O_TEXT);
    vector<pair<int,int>>mov2;

    for(auto pair : mov){
        mov2.emplace_back(pair.first+1, pair.second+1);
    }
    sort(mov2.begin(), mov2.end());

    cout << mov2 << endl;
}

void MainGame ::PawnChange(Piece *pawnCheck, int x, int y, int newX) {
    char change;
    if(pawnCheck->getColor() == BLACK){
        if(newX == 7){
            bool err = false;
            do {
                if(err){
                    cout << "Invalid Input ... TryAgain!" << endl;
                }

                cout << "Choose one [ (H for Horse), (B for Bishop), (Q for Queen) ] : ";
                cin >> change;
                if(change != 'H' && change != 'B' && change != 'Q'){
                    err = true;
                    continue;
                }
            }while(err);

            switch(change){
                case 'H' :
                    game->getBoard()->getField(x,y)->setPiece(new Horse(),BLACK,"BH");
                    break;
                case 'B' :
                    game->getBoard()->getField(x,y)->setPiece(new Bishop(),BLACK,"BB");
                    break;
                case 'Q' :
                    game->getBoard()->getField(x,y)->setPiece(new Queen(),BLACK,"BQ");
                    break;
            }
        }
    }
    else{
        if(newX == 0){
            bool err = false;
            do {
                if(err){
                    cout << "Invalid Input ... TryAgain!" << endl;
                }

                cout << "Choose one [ (H for Horse), (B for Bishop), (Q for Queen) ] : ";
                cin >> change;
                if(change != 'H' && change != 'B' && change != 'Q'){
                    err = true;
                    continue;
                }
            }while(err);

            switch(change){
                case 'H' :
                    game->getBoard()->getField(x,y)->setPiece(new Horse(),WHITE,"WH");
                    break;
                case 'B' :
                    game->getBoard()->getField(x,y)->setPiece(new Bishop(),WHITE,"WB");
                    break;
                case 'Q' :
                    game->getBoard()->getField(x,y)->setPiece(new Queen(),WHITE,"WQ");
                    break;
            }
        }
    }
}

void MainGame :: PlayerTurn(int num, bool& error, Colors col){
    _setmode(_fileno(stdout), _O_TEXT);
    do{
        if(error){
            cout << "Again Quick!" << endl;
        }

        error = false;
        bool kingDanger = false;
        if(inCheck(col)){
            cout << "Your King is in Check Protected Him!" << endl;
            kingDanger = true;
            pair<int,int>kingPosition = findKingPosition(col);
            set<pair<int,int>>KingAvaliableMov = CheckKingMoves(kingPosition.first, kingPosition.second, col);
            if(!KingAvaliableMov.empty()){
                cout << "Avaliable Moves to Protected King: " << endl;
                cout << "King ";
                printMoves(KingAvaliableMov);
            }
            else{
                cout << "No Avaliable Move for your King" <<endl;
            }
        }

        cout << "Player " << num <<  " turn " << endl;
        cout << "Enter Cell Move : ";

        int x, y;
        cin >> x >> y;
        x--;y--;

        if((x >= 0 && x < 8) && (y >= 0 && y < 8)) {
            if (dynamic_cast<Empty *>(game->getBoard()->getField(x, y)->getPiece())) {
                cout << "Empty Place ... Try Again! " << endl;
                error = true;
                continue;
            }
            if (game->getBoard()->getField(x, y)->getPiece()->getColor() != col) {
                cout << "Wrong Color ... Try Again! " << endl;
                error = true;
                continue;
            }

            set<pair<int, int>> newMoves;
            for (auto pair: game->getBoard()->getField(x, y)->getMoves(x, y)) {
                newMoves.insert(pair);
            }

            if (!newMoves.empty()) {
                set<pair < int, int>> validMoves;

                // Check if Color is Same Remove move
                validMoves = CheckMoves(newMoves, col);
                if (!validMoves.empty()) {
                    printMoves(validMoves);

                    cout << "Choose Direction: ";
                    int newX, newY;
                    cin >> newX >> newY;
                    newX--;
                    newY--;

                    if (!validMoves.count({newX, newY})) {
                        cout << "Error Not Valid Move ... TryAgain!" << endl;
                        error = true;
                        continue;
                    }
                    Piece* pawnCheck = game->getBoard()->getField(x,y)->getPiece();
                    if(dynamic_cast<Pawn*>(pawnCheck)){
                        PawnChange(pawnCheck, x, y, newX);
                    }
                    game->getBoard()->swapPiece({x, y}, {newX, newY});
                } else {
                    cout << "Can't Move This Piece ... TryAgain" << endl;
                    error = true;
                    continue;
                }
            } else {
                cout << "Can't Move This Piece ... TryAgain" << endl;
                error = true;
                continue;
            }
        }
        else{
            cout << "Out of the GRID ... Try Again!" << endl;
            error = true;
            continue;
        }
    }while(error);
}


Colors MainGame :: checkWinner(){
    for (int i = 0; i < 8; ++i){
        for (int j = 0; j < 8; ++j){
            Piece* ptrP = game->getBoard()->getField(i,j)->getPiece();
            if(dynamic_cast<King*>(ptrP)){
                return ptrP->getColor();
            }
        }
    }
}


void MainGame ::  ChooseColor(Colors& player1, Colors& player2){
    _setmode(_fileno(stdout), _O_TEXT);
    char ch;
    bool error = false;
    do {
        if(error){
            cout << "Please Enter B or W only!" << endl;
            error = false;
        }
        cout << "Player1 Please Choose Color (B for Black), (W for White) : ";
        cin >> ch;
        if(ch != 'B' && ch != 'W'){
            error = true;
        }
    }while(error);

    player1 = ch == 'B' ? BLACK : WHITE;
    player2 = ch == 'B' ? WHITE : BLACK;
}




int main() {
    game = new Game();
    MainGame Chess;
    Chess.fillBoard();
    bool error = false;

    // Choose Colors;
    Colors player1, player2;
    Chess.ChooseColor(player1, player2);


    //Main Game
    do{

        Chess.PlayerTurn(1,error,player1);

        Chess.fillBoard();

        if(game->getBoard()->isCheckMate()) break;

        Chess.PlayerTurn(2, error, player2);

        Chess.fillBoard();

    }while(!(game->getBoard()->isCheckMate()));

    Colors winnerColor = Chess.checkWinner();

    wcout << endl << (player1 == winnerColor ? "Player 1 Wins !!!" : "Player 2 Wins !!!") << endl;

}
