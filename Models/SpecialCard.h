//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_SPECIALCARD_H
#define MONOPOLY_SPECIALCARD_H

#include "Spot.h"
#include "Enums/SpecialCardAction.h"

class SpecialCard: public Spot{
public:
    explicit SpecialCard();
    explicit SpecialCard(string, string, int, int, SpecialCardAction);
    explicit SpecialCard(string, string, int, SpecialCardAction);
    string getText();
    int getAmountToPayOrCollect();
    int getPositionToGo();
    SpecialCardAction getAction();
    string toString();

private:
    string text;
    int amountToPayOrCollect;
    int positionToGo;
    SpecialCardAction action;
};


#endif //MONOPOLY_SPECIALCARD_H
