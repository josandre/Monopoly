//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "Spot.h"
Spot::Spot(string name, SpotType type) {
    this->name = name;
    this->type = type;
}

string Spot::getName() {
    return this->name;
}

SpotType Spot::getType() {
    return this->type;
}