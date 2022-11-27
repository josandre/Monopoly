//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_SPOT_H
#define MONOPOLY_SPOT_H
using namespace std;
#include <iostream>;
#include "Enums/SpotType.h"

class Spot {
public:
    Spot(string, SpotType);
    string getName();
    SpotType getType();

protected:
    string name;
    SpotType type;

};


#endif //MONOPOLY_SPOT_H
