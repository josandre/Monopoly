//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_JAIL_H
#define MONOPOLY_JAIL_H


#include "Spot.h"

class Jail : public Spot{
public:
    Jail(string, int);
    int getBlockMoves();
    void setBlockMoves(int);
private:
    int blockMoves;
};


#endif //MONOPOLY_JAIL_H
