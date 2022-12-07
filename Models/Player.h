//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H
#include <iostream>
#include "../Models/Token.h"
#include "../Core/Node.h"
#include "../Models/Spot.h"

using namespace std;

class Player {
public:
    explicit Player(int, string, Node<Spot>*, int, int, Token, int);
    explicit Player();
    string toString();
    int getId();
    string getName();
    Node<Spot> *getSpot();
    void setSpot(Node<Spot>*);
    int getMoney();
    void setMoney(int);
    int getBlockMoves();
    void setBlockMoves(int);
    Token getItem();
    int getTurn();
    void setTurn(int);

private:
    int id;
    string name;
    Node<Spot> *spot;
    int money;
    int blockMoves;
    Token item;
    int turn;

};


#endif //MONOPOLY_PLAYER_H
