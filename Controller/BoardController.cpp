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
#include "../Models/Tax.h"
#include "../Models/Property.h"
#include "../Models/Free.h"
#include "../Models/Jail.h"
#include "../Controller/Initialize.h"

BoardController::BoardController() {
    this->tokens =  new List<Token>(6);
    this->players = *new List<Player>();
    this->playerTurns = *new Queue<Player>;
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




string BoardController::getAvailbleTokens() {
    Node<Token> *aux = this->tokens->getHead();
    string result = "";
    while (aux != nullptr){
        if(!aux->getData().getInUse()){
            result +=  aux->getData().toString();
            aux = aux->getNext();

            result += "\n ---------------------------------------\n";

        }

    }

    result += "";
    return result;
}

int BoardController::throwDice() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 6);
    return (int)dist(mt);
}

