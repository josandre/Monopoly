//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_BOARDCONTROLLER_H
#define MONOPOLY_BOARDCONTROLLER_H


#include "../Core/List.h"
#include "../Models/Token.h"
#include "../Models/Player.h"
#include "../Core/Queue.h"
#include <random>

class BoardController {
public:
    explicit BoardController();
    void initializeTokens();
    string getAvailbaleTokens();
    int throwDice();

private:
    List<Token> tokens;
    List<Player> players;
    Queue<Player> playerTurns;

};


#endif //MONOPOLY_BOARDCONTROLLER_H
