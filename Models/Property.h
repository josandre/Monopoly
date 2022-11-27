//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_PROPERTY_H
#define MONOPOLY_PROPERTY_H
using namespace std;
#include <iostream>
#include "Spot.h"
#include "Player.h"
#include "Enums/Color.h"

class Property : public Spot {
public:
    explicit Property(string name, Color color, int cost, int rent,
                       int mortgage, int costHouse, int costHotel, int costUnMortgage);
    Color getColor();
    string toString();
    int getCost();
    int getRent();
    int getAmountHouses();
    void setAmountHouses(int);
    bool getHasHotel();
    void setHasHotel(bool);
    int getMortgage();
    int getCostHouse();
    int getCostHotel();
    int getCostUnMortgage();
    Player *getOwner();
    void setOwner(Player *);

private:
    Color color;
    int cost;
    int rent;
    int amountHouses;
    bool hasHotel;
    int mortgage;
    int costHouse;
    int costHotel;
    int costUnmortgage;
    Player *owner;

};


#endif //MONOPOLY_PROPERTY_H
