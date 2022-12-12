//
// Created by Jocselyn Aguilar on 6/12/22.
//

#ifndef MONOPOLY_INITIALIZE_H
#define MONOPOLY_INITIALIZE_H
#include "../Models/Token.h"
#include "../Models/SpecialCard.h"
#include "../Models/Player.h"
#include "../Core/List.h"
#include "../Core/Stack.h"
#include "../Core/CircularList.h"



class Initialize {
public:
    Initialize();
    void InitializeGame(List<Token> *, Stack<SpecialCard> *, Stack<SpecialCard> *, CircularList<Spot*> *, List<Player> *);


private:
    void InitializeTokens(List<Token> *);
    void InitializeFortuneSpecialCards(Stack<SpecialCard> *);
    void InitializeCommunalArkSpecialCard(Stack<SpecialCard> *);
    void InitializeBoard(CircularList<Spot*>  *);
    void InitializeRecords(List<Player>  *);
};


#endif //MONOPOLY_INITIALIZE_H
