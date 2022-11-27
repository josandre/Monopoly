//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "Property.h"
#include "Enums/SpotType.h"

Property::Property(string name, Color color, int cost, int rent,
                    int mortgage, int costHouse, int costHotel, int costUnMortgage)
        : Spot(name, PropertyType) {
    this->color = color;
    this->cost = cost;
    this->rent = rent;
    this->amountHouses = 0;
    this->hasHotel = false;
    this->mortgage = mortgage;
    this->costHouse = costHouse;
    this->costHotel = costHotel;
    this->costUnmortgage = costUnMortgage;
    this->owner = nullptr;
}

Color Property::getColor() {
    return this->color;
}

int Property::getCost() {
    return this->cost;
}

int Property::getRent() {
    return this->rent;
}

int Property::getAmountHouses() {
    return this->amountHouses;
}

void Property::setAmountHouses(int amount) {
    this->amountHouses = amount;
}

bool Property::getHasHotel() {
    return this->hasHotel;
}

void Property::setHasHotel(bool hasHotel) {
    this->hasHotel = hasHotel;
}

int Property::getMortgage() {
    return this->mortgage;
}

int Property::getCostHouse() {
    return this->costHouse;
}

int Property::getCostHotel() {
    return this->costHotel;
}

int Property::getCostUnMortgage() {
    return this->costUnmortgage;
}

Player *Property::getOwner(){
    return this->owner;
}

void Property::setOwner(Player *newOwner) {
    this->owner = newOwner;
}

string Property::toString() {
    string hotel = this->hasHotel ? ", Hotel: 1" : ", No Hotel";


    return "Name: " + this->name +  ", Color: " + to_string(this->color) + "," + ", Cost: " + to_string(this->cost) +
    ", Rent: " + to_string(this->rent) +  ", Houses: " + to_string(this->amountHouses) +  hotel  + ", Mortgage: " +
            to_string(this->mortgage) + ", Cost house: " + to_string(this->costHouse) + ", Cost hotel: " + to_string(this->costHotel) +
            ", Cost unmortgage: " + to_string(this->costUnmortgage);
}