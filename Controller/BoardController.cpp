//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "BoardController.h"

#include "../Models/SpecialCard.h"

#include "../Core/Node.cpp"
#include "../Core/List.cpp"
#include "../Core/Queue.cpp"
#include "../Core/Stack.cpp"
#include "../Core/CircularList.cpp"

#include "../Models/Property.h"

#include "../Controller/Initialize.h"

BoardController::BoardController() {
    this->tokens =  new List<Token>(6);
    this->players = new List<Player>();
    this->playerTurns = new Queue<Player>;
    this->Mainfortune = new Stack<SpecialCard>;
    this->Secondfortune = new Stack<SpecialCard>;
    this->MainComunalArk = new Stack<SpecialCard>;
    this->SecondComunalArk = new Stack<SpecialCard>;
    this->board = new CircularList<Spot>;
    Initialize initGame = *new Initialize();
    initGame.InitializeGame(this->tokens, this->Mainfortune, this->MainComunalArk, this->board );
}

SpecialCard BoardController::getActionSpecialCard() {
    SpecialCard card =  Mainfortune->pop();
    this->Secondfortune->push(card);
    if(Mainfortune->isEmpty()){
        this->Mainfortune = Secondfortune;
        this->Secondfortune = new Stack<SpecialCard>();
    }
    return card;
}

List<Player> *BoardController::getPlayers() {
    return this->players;
}

Queue<Player> *BoardController::getPlayerInTurns() {
    return this->playerTurns;
}


CircularList<Spot> *BoardController::getBoard() {
    return this->board;
}

string BoardController::getAvailableTokens() {
    Node<Token> *aux = this->tokens->getHead();
    string result = "";
    while (aux != nullptr){
        if(!aux->getData().getInUse()){
            result +=  aux->getData().toString();
            result += "\n ---------------------------------------\n";
        }

        aux = aux->getNext();
    }

    result += "";
    return result;
}

string  BoardController::getPlayersReady() {
    Node<Player> *aux = this->playerTurns->getFront();
    string result = "";
    while (aux != nullptr){
        result += aux->getData().toString();
        result += "\n --------------------------------------------------------------------------------------------------------\n";
        aux = aux->getNext();
    }
    result += "";
    return result;
}



Token BoardController::selectToken(int idSelected) {
    Token *token = &this->tokens->findByIndex(idSelected-1);

    if(token->getId() == idSelected) {
        token->setInUse(true);
    }

    return *token;
}

int BoardController::throwDice() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 6);
    return (int)dist(mt);
}

