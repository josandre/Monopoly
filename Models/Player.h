//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H
#include <iostream>
#include "../Models/Token.h"
#include "../Core/Node.h"
#include "../Core/Queue.h"

#include "../Models/Spot.h"
#include "../Models/SpecialCard.h"


using namespace std;

class Player {
public:
    explicit Player(string, Node<Spot*>*, int, int, Token, int);
    explicit Player();
    string toString();
    string getName();
    Node<Spot*> *getSpot();
    void setSpot(Node<Spot*>*);
    int getMoney();
    void setMoney(int);
    int getBlockMoves();
    void setBlockMoves(int);
    Token getItem();
    int getTurn();
    void setTurn(int);
    Queue<SpecialCard> *getCards();
    int getRound();
    void setRound();

private:

    string name;
    Node<Spot*> *spot;
    int money;
    int blockMoves;
    Token item;
    int turn;
    Queue<SpecialCard> *cards;
    int round = 0;
};


#endif //MONOPOLY_PLAYER_H
