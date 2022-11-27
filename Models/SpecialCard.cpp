//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "SpecialCard.h"

SpecialCard::SpecialCard(string name, string text, int amount, int position, SpecialCardAction action) :
    Spot(name, SpecialCardType){
    this->text = text;
    this->amountToPayOrCollect = amount;
    this->positionToGo = position;
    this->action = action;
}

string SpecialCard::getText() {
    return this->text;
}

int SpecialCard::getAmountToPayOrCollect() {
    return this->amountToPayOrCollect;
}

int SpecialCard::getPositionToGo() {
    return this->positionToGo;
}

SpecialCardAction SpecialCard::getAction() {
    return this->action;
}


string SpecialCard::toString() {
    return "Name: " + this->getName() + ", Text: "  + this->getText() +
        ", Amount to pay or collect: " + to_string(this->getAmountToPayOrCollect()) +
        ", Position to go: " + to_string(this->getPositionToGo()) + ", Action: " + to_string(this->getAction());
}