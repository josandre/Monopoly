//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_TAX_H
#define MONOPOLY_TAX_H


#include "Spot.h"

class Tax: public Spot {
public:
    Tax(string, int);
    int getCost();
private:
    int cost;
};


#endif //MONOPOLY_TAX_H
