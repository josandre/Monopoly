//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "Item.h"

Item::Item(int id, std::string name, bool inUse) {
    this->id = id;
    this->name = name;
    this->inUse = false;
}

Item::Item() {}

int Item::getId(){
    return this->id;
}

string Item::getName() {
    return this->name;
}

bool Item::getInUse() {
    return this->inUse;
}

string Item::toString() {
    string inUse = "";

    if(getInUse()){
        inUse = "Not available";
    }else{
        inUse = "available";
    }

    return "Id: " + to_string(this->id) +
    "Name: " + this->name + "InUse: " + inUse;
}