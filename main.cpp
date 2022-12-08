#include <iostream>
#include "Models/SpecialCard.h"
#include "Controller/BoardController.h"
#include "Models/Player.cpp"
#include "Core/List.cpp"
#include "Core/CircularList.cpp"
#include "Core/Queue.cpp"
using namespace std;

void InitGame(){


}

bool idToken(int tokenId){
    if(tokenId <= 6 && to_string(tokenId) != ""){
        return true;
    }

    return false;
}

Token validToken(int id, BoardController *board){
    Token token;
    while (!idToken(id)){
        cout << "Id Invalid, you need a token to start the game" << endl;
    }

    if(idToken(id)){
        token = board->selectToken(id);
    }

    return token;
}

void InitTurns( BoardController *board){
    int length = board->getPlayers()->getLength();

    int acum = 0;
    while (acum < length){
        Player *player = new Player(board->getPlayers()->findByIndex(acum));
        board->getPlayerInTurns()->enQueue(*player);
        acum ++;
    }

    cout << board->getPlayersReady() << endl;

}

void InitPlayers(int players, BoardController *board){

    CircularList<Spot> *boardGame = board->getBoard();

    for(int i = 0; i < players; i++){
        cout << "Player " << (i+1) << "- Insert your name" << endl;
        string name;
        cin >> name;
        Node<Spot> *spot = new Node<Spot>(boardGame->findByIndex(0));
        int money = 1500;
        int blockMoves = 0;
        cout << board->getAvailableTokens() << endl;
        cout << "Choose a token ID, to play with!" << endl;
        int id;
        cin >> id;
        Token token = validToken(id, board);
        int turn = board->throwDice();
        Player player = *new Player(name, spot, money, blockMoves, token, turn);
        board->getPlayers()->addDescending(player);
    }

    //cout << board->getPlayers()->toString() << endl;

    InitTurns(board);
}

int main() {
    auto *board = new BoardController();
    cout << "How many players are going to play? (6 max)" << endl;
    int players;
    cin >> players;

    if(players > 6 || players < 2){
        cout << "The limit is six players and the minimum is two" << endl;
    } else{
        InitPlayers(players, board);
    }
}
