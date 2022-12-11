//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "SpecialCard.h"
SpecialCard::SpecialCard() : Spot("", SpecialCardType) {}

SpecialCard::SpecialCard(string name, SpecialCardTypes type) : Spot(name, SpecialCardType) {
    this->cardType = type;
}

SpecialCard::SpecialCard(string name, string text, int amount, int position, SpecialCardAction action) :
    Spot(name, SpecialCardType){
    this->text = text;
    this->amountToPayOrCollect = amount;
    this->positionToGo = position;
    this->action = action;
}

SpecialCard::SpecialCard(string name, string text, int position, SpecialCardAction action) :
        Spot(name, SpecialCardType){
    this->text = text;
    this->positionToGo = position;
    this->action = action;
}

string SpecialCard::getText() {
    return this->text;
}

SpecialCardTypes SpecialCard::getCardType() {
    return this->cardType;
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
    return "Name: " + this->getName() + ", Text: "  + this->getText();
}