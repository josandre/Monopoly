//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H
#include <iostream>
#include "../Models//Token.h"

using namespace std;

class Player {
public:
    explicit Player(int, string, int, int, int, Token, int);
    explicit Player();
    string toString();
    int getId();
    string getName();
    int getPosition();
    void setPosition(int);
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
    int position;
    int money;
    int blockMoves;
    Token item;
    int turn;

};


#endif //MONOPOLY_PLAYER_H
