//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "Token.h"

Token::Token(int id, string name) {
    this->id = id;
    this->name = name;
    this->inUse = false;
}

Token::Token() {}

int Token::getId(){
    return this->id;
}

string Token::getName() {
    return this->name;
}

bool Token::getInUse() {
    return this->inUse;
}

void Token::setInUse(bool newValue) {
    this->inUse = newValue;
}

string Token::toString() {
    string inUse = "";

    if(getInUse()){
        inUse = "Not available";
    }else{
        inUse = "available";
    }

    return "Id: " + to_string(this->id) +
    ", Name: " + this->name + ", In use: " + inUse;
}