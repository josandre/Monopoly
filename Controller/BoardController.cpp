//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "BoardController.h"
#include "../Models/Token.h"
#include "../Models/SpecialCard.h"
#include "../Core/List.cpp"
#include "../Core/Queue.cpp"
#include "../Core/Stack.cpp"

BoardController::BoardController() {
    this->tokens =  *new List<Token>(6);
    this->players = *new List<Player>();
    this->playerTurns = *new Queue<Player>;
    this->Mainfortune = *new Stack<SpecialCard>;
    this->Secondfortune = *new Stack<SpecialCard>;
    this->MainComunalArk = *new Stack<SpecialCard>;
    this->SecondComunalArk = *new Stack<SpecialCard>;
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


void BoardController::initializeSpecialCardsFortune() {
    SpecialCard fortune1 = *new SpecialCard("Fortune", "Advance to the nearest service, if it is for sale you can buy it, otherwise you must pay the owner 10 times what it is worth", 0, Pay);
    SpecialCard fortune2 = *new SpecialCard("Fortune", "advance to pier", 0, GoTo);
    SpecialCard fortune3 = *new SpecialCard("Fortune", "pay the speeding ticket", 15, 0, Pay);
    SpecialCard fortune4 = *new SpecialCard("Fortune", "You have been elect as mayor, you have to pay 50 to every player", 50, 0, Pay);
    SpecialCard fortune5 = *new SpecialCard("Fortune", "You have to fix your houses, pay 25 for every house you have",25, 0, Pay);
    SpecialCard fortune6 = *new SpecialCard("Fortune", "You have to fix your hotels, pay 100 for every house you have",100, 0, Pay);
    SpecialCard fortune7 = *new SpecialCard("Fortune", "Go back 3 spaces", 3, GoTo);
    SpecialCard fortune8 = *new SpecialCard("Fortune", "Go to San Carlos Square ", 0, GoTo);
    SpecialCard fortune9 = *new SpecialCard("Fortune", "Advance to the nearest railway if it is for sale you can buy it, otherwise pay double the rent", 0, CalculatePay);
    SpecialCard fortune10 = *new SpecialCard("Fortune", "Ask the bank for 150 for loan compliance",150, 0, Collect);
    SpecialCard fortune11 = *new SpecialCard("Fortune", "get out of jail free", 0, ExitJail);
    SpecialCard fortune12 = *new SpecialCard("Fortune", "The bank pays you 50",50, 0, Collect);
    SpecialCard fortune13 = *new SpecialCard("Fortune", "Go to the jail, and no collect the exit tax", 0, GoTo);
    SpecialCard fortune14 = *new SpecialCard("Fortune", "Get 100 from the bank",100, 0, Collect);
    SpecialCard fortune15 = *new SpecialCard("Fortune", "Advance 7 spots", 7, GoTo);
    SpecialCard fortune16 = *new SpecialCard("Fortune", "You have to pay to he bank for taxes 100",100, 0, Pay);

    this->Mainfortune.push(fortune1);
    this->Mainfortune.push(fortune2);
    this->Mainfortune.push(fortune3);
    this->Mainfortune.push(fortune4);
    this->Mainfortune.push(fortune5);
    this->Mainfortune.push(fortune6);
    this->Mainfortune.push(fortune7);
    this->Mainfortune.push(fortune8);
    this->Mainfortune.push(fortune9);
    this->Mainfortune.push(fortune10);
    this->Mainfortune.push(fortune11);
    this->Mainfortune.push(fortune12);
    this->Mainfortune.push(fortune13);
    this->Mainfortune.push(fortune14);
    this->Mainfortune.push(fortune15);
    this->Mainfortune.push(fortune16);
}

void BoardController::initializeSpecialCardsComunalArk() {
    SpecialCard comunalArk1 = *new SpecialCard("Comunal Ark", "Collect 25", 25, 0, Collect);
    SpecialCard comunalArk2 = *new SpecialCard("Comunal Ark", "Collect 50 for sale", 50, 0, Collect);
    SpecialCard comunalArk3 = *new SpecialCard("Comunal Ark", "Leave the jail free", 25, 0, ExitJail);
    SpecialCard comunalArk4 = *new SpecialCard("Comunal Ark", "Tax return, collect 20", 20, 0, Collect);
    SpecialCard comunalArk5 = *new SpecialCard("Comunal Ark", "Go to the jail", 0, GoTo);
    SpecialCard comunalArk6 = *new SpecialCard("Comunal Ark", "pay 25 for taxes", 25, 0, Pay);
    SpecialCard comunalArk7 = *new SpecialCard("Comunal Ark","You won second prize in the beauty contest. Collect 10", 10, 0, Collect);
    SpecialCard comunalArk8 = *new SpecialCard("Comunal Ark", "Pay 100 for medical account", 100, 0, Pay);
    SpecialCard comunalArk9 = *new SpecialCard("Comunal Ark", "Pay college 50", 50, 0, Pay);
    SpecialCard comunalArk10 = *new SpecialCard("Comunal Ark", "life insurance expiration, get 100", 100, 0, Collect);
    SpecialCard comunalArk11 = *new SpecialCard("Comunal Ark", "Bank error, get 200", 200, 0, Collect);
    SpecialCard comunalArk12 = *new SpecialCard("Comunal Ark", "Happy birthday, get 10", 10, 0, Collect);
    SpecialCard comunalArk13 = *new SpecialCard("Comunal Ark", "inheritance, get 100", 100, 0, Collect);
    SpecialCard comunalArk14 = *new SpecialCard("Comunal Ark", "For fixes, pay 100", 100, 0, Pay);
    SpecialCard comunalArk15 = *new SpecialCard("Comunal Ark", "For vacation, get 100", 100, 0, Collect);
    SpecialCard comunalArk16 = *new SpecialCard("Comunal Ark", "Pay 100 to build a new orphan house", 100, 0, Pay);

    this->MainComunalArk.push(comunalArk1);
    this->MainComunalArk.push(comunalArk2);
    this->MainComunalArk.push(comunalArk3);
    this->MainComunalArk.push(comunalArk4);
    this->MainComunalArk.push(comunalArk5);
    this->MainComunalArk.push(comunalArk6);
    this->MainComunalArk.push(comunalArk7);
    this->MainComunalArk.push(comunalArk8);
    this->MainComunalArk.push(comunalArk9);
    this->MainComunalArk.push(comunalArk10);
    this->MainComunalArk.push(comunalArk11);
    this->MainComunalArk.push(comunalArk12);
    this->MainComunalArk.push(comunalArk13);
    this->MainComunalArk.push(comunalArk14);
    this->MainComunalArk.push(comunalArk15);
    this->MainComunalArk.push(comunalArk16);
}

SpecialCard BoardController::getActionSpecialCard() {
    SpecialCard card =  Mainfortune.pop();
    this->Secondfortune.push(card);
    if(Mainfortune.isEmpty()){
        this->Mainfortune = Secondfortune;
        this->Secondfortune = *new Stack<SpecialCard>();
    }
    return card;

}



string BoardController::getAvailbleTokens() {
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