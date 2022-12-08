//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "Tax.h"
Tax::Tax(string name, int cost): Spot(name, TaxType) {
    this->cost = cost;
}

int Tax::getCost() {
    return this->cost;
}