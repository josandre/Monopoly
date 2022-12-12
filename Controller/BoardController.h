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
    string getAvailableTokens();
    Token selectToken(int);
    int throwDice();
    List<Player> *getPlayers();
    Queue<Player> *getPlayerInTurns();
    SpecialCard getActionSpecialCard(SpecialCardTypes );
    CircularList<Spot*> *getBoard();
    string getPlayersReady();
    Node<Spot*> *getNewSpot(int, Player*);
    Node<Spot*> *getJail();
    Player* findPlayerByToken(Token);
    void endGame(bool);
    Player* getWinner();
    string getRecords();
    void loadGame();

private:
    List<Token> *tokens;
    List<Player> *players;
    List<Player> *records;
    Queue<Player> *playerTurns;
    Stack<SpecialCard> *Mainfortune;
    Stack<SpecialCard> *Secondfortune;
    Stack<SpecialCard> *MainComunalArk;
    Stack<SpecialCard> *SecondComunalArk;
    CircularList<Spot*> *board;
    Node<Spot*> *jail;
    Node<Spot*> *findSpotByName(string);
    void saveRecords();
    void saveGame();
    void savePlayersState();
    void saveGameBoardState();
    void loadPlayersState();
    void loadGameBoardState();
};


#endif //MONOPOLY_BOARDCONTROLLER_H
