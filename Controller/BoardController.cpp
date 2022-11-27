//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "BoardController.h"
#include "../Models/Token.h"
#include "../Core/List.cpp"
#include "../Core/Queue.cpp"


BoardController::BoardController() {
    this->tokens =  *new List<Token>(6);
    this->players = *new List<Player>();
    this->playerTurns = *new Queue<Player>;
}

void BoardController::initializeTokens() {
    Token duck = *new Token(1, "Duck");
    Token hat = *new Token(2, "Hat");
    Token dino = *new Token(3, "Dino");
    Token cat = *new Token(4, "Cat");
    Token dog = *new Token(5, "Dog");
    Token ship = *new Token(6, "Ship");
    this->tokens.add(duck);
    this->tokens.add(hat);
    this->tokens.add(dino);
    this->tokens.add(cat);
    this->tokens.add(dog);
    this->tokens.add(ship);
}

string BoardController::getAvailbaleTokens() {
    Node<Token> *aux = this->tokens.getHead();
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