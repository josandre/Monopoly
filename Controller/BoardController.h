//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_BOARDCONTROLLER_H
#define MONOPOLY_BOARDCONTROLLER_H


#include "../Core/List.h"
#include "../Models/Token.h"
#include "../Models/Player.h"
#include "../Models/SpecialCard.h"
#include "../Core/Queue.h"
#include "../Core/Stack.h"
#include "../Core/CircularList.h"
#include <random>

class BoardController {
public:
    explicit BoardController();
    string getAvailbleTokens();
    int throwDice();
    SpecialCard getActionSpecialCard();


private:
    List<Token> *tokens;
    List<Player> players;
    Queue<Player> playerTurns;
    Stack<SpecialCard> *Mainfortune;
    Stack<SpecialCard> *Secondfortune;
    Stack<SpecialCard> *MainComunalArk;
    Stack<SpecialCard> *SecondComunalArk;
    CircularList<Spot> *board;
};


#endif //MONOPOLY_BOARDCONTROLLER_H
