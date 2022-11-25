//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_PLAYER_H
#define MONOPOLY_PLAYER_H
#include <iostream>
#include "../Models//Item.h"

using namespace std;

class Player {
private:
    explicit Player(int, string, int, int, int, Item);
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
    Item getItem();

public:
    int id;
    string name;
    int position;
    int money;
    int blockMoves;
    Item item;

};


#endif //MONOPOLY_PLAYER_H
