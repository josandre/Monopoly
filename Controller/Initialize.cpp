//
// Created by Jocselyn Aguilar on 6/12/22.
//

#include "Initialize.h"
#include "../Core/Node.cpp"
#include "../Models/Free.h"
#include "../Models/Jail.h"
#include "BoardController.h"
#include "../Models/SpecialCard.h"
#include "../Core/List.cpp"
#include "../Core/Queue.cpp"
#include "../Core/Stack.cpp"
#include "../Core/CircularList.cpp"
#include "../Core/CircularList.h"
#include "../Models/Tax.h"
#include "../Models/Property.h"

Initialize::Initialize() {}

void Initialize::InitializeTokens(List<Token> *tokens) {
        Token duck = *new Token(1, "Duck");
        Token hat = *new Token(2, "Hat");
        Token dino = *new Token(3, "Dino");
        Token cat = *new Token(4, "Cat");
        Token dog = *new Token(5, "Dog");
        Token ship = *new Token(6, "Ship");
        tokens->add(duck);
        tokens->add(hat);
        tokens->add(dino);
        tokens->add(cat);
        tokens->add(dog);
        tokens->add(ship);
}

void Initialize::InitializeFortuneSpecialCards(Stack<SpecialCard> *Mainfortune) {

        SpecialCard fortune1 = *new SpecialCard("Fortune", "Advance to the nearest service, if it is for sale you can buy it, otherwise you must pay the owner 10 times what it is worth", 0, Pay);
        SpecialCard fortune2 = *new SpecialCard("Fortune", "advance to pier", 0, GoTo);
        SpecialCard fortune3 = *new SpecialCard("Fortune", "pay the speeding ticket", 15, 0, Pay);
        SpecialCard fortune4 = *new SpecialCard("Fortune", "You have been elect as mayor, you have to pay 50 to every player", 50, 0, Pay);
        SpecialCard fortune5 = *new SpecialCard("Fortune", "You have to fix your houses, pay 25 for every house you have",25, 0, Pay);
        SpecialCard fortune6 = *new SpecialCard("Fortune", "You have to fix your hotels, pay 100 for every house you have",100, 0, Pay);
        SpecialCard fortune7 = *new SpecialCard("Fortune", "Go back 3 spaces", 3, GoTo);
        SpecialCard fortune8 = *new SpecialCard("Fortune", "Go to San Carlos Square ", 0, GoTo);
        SpecialCard fortune9 = *new SpecialCard("Fortune", "Advance to the nearest railway if it is for sale you can buy it, otherwise pay double the rent", 0, CalculatePay);
        SpecialCard fortune10 = *new SpecialCard("Fortune", "Ask the bank for 150 for loan compliance",150, 0, Collect);
        SpecialCard fortune11 = *new SpecialCard("Fortune", "get out of jail free", 0, ExitJail);
        SpecialCard fortune12 = *new SpecialCard("Fortune", "The bank pays you 50",50, 0, Collect);
        SpecialCard fortune13 = *new SpecialCard("Fortune", "Go to the jail, and no collect the exit tax", 0, GoTo);
        SpecialCard fortune14 = *new SpecialCard("Fortune", "Get 100 from the bank",100, 0, Collect);
        SpecialCard fortune15 = *new SpecialCard("Fortune", "Advance 7 spots", 7, GoTo);
        SpecialCard fortune16 = *new SpecialCard("Fortune", "You have to pay to he bank for taxes 100",100, 0, Pay);

        Mainfortune->push(fortune1);
        Mainfortune->push(fortune2);
        Mainfortune->push(fortune3);
        Mainfortune->push(fortune4);
        Mainfortune->push(fortune5);
        Mainfortune->push(fortune6);
        Mainfortune->push(fortune7);
        Mainfortune->push(fortune8);
        Mainfortune->push(fortune9);
        Mainfortune->push(fortune10);
        Mainfortune->push(fortune11);
        Mainfortune->push(fortune12);
        Mainfortune->push(fortune13);
        Mainfortune->push(fortune14);
        Mainfortune->push(fortune15);
        Mainfortune->push(fortune16);

}

void Initialize::InitializeCommunalArkSpecialCard(Stack<SpecialCard> *MainComunalArk) {
    SpecialCard comunalArk1 = *new SpecialCard("Comunal Ark", "Collect 25", 25, 0, Collect);
    SpecialCard comunalArk2 = *new SpecialCard("Comunal Ark", "Collect 50 for sale", 50, 0, Collect);
    SpecialCard comunalArk3 = *new SpecialCard("Comunal Ark", "Leave the jail free", 25, 0, ExitJail);
    SpecialCard comunalArk4 = *new SpecialCard("Comunal Ark", "Tax return, collect 20", 20, 0, Collect);
    SpecialCard comunalArk5 = *new SpecialCard("Comunal Ark", "Go to the jail", 0, GoTo);
    SpecialCard comunalArk6 = *new SpecialCard("Comunal Ark", "pay 25 for taxes", 25, 0, Pay);
    SpecialCard comunalArk7 = *new SpecialCard("Comunal Ark","You won second prize in the beauty contest. Collect 10", 10, 0, Collect);
    SpecialCard comunalArk8 = *new SpecialCard("Comunal Ark", "Pay 100 for medical account", 100, 0, Pay);
    SpecialCard comunalArk9 = *new SpecialCard("Comunal Ark", "Pay college 50", 50, 0, Pay);
    SpecialCard comunalArk10 = *new SpecialCard("Comunal Ark", "life insurance expiration, get 100", 100, 0, Collect);
    SpecialCard comunalArk11 = *new SpecialCard("Comunal Ark", "Bank error, get 200", 200, 0, Collect);
    SpecialCard comunalArk12 = *new SpecialCard("Comunal Ark", "Happy birthday, get 10", 10, 0, Collect);
    SpecialCard comunalArk13 = *new SpecialCard("Comunal Ark", "inheritance, get 100", 100, 0, Collect);
    SpecialCard comunalArk14 = *new SpecialCard("Comunal Ark", "For fixes, pay 100", 100, 0, Pay);
    SpecialCard comunalArk15 = *new SpecialCard("Comunal Ark", "For vacation, get 100", 100, 0, Collect);
    SpecialCard comunalArk16 = *new SpecialCard("Comunal Ark", "Pay 100 to build a new orphan house", 100, 0, Pay);

    MainComunalArk->push(comunalArk1);
    MainComunalArk->push(comunalArk2);
    MainComunalArk->push(comunalArk3);
    MainComunalArk->push(comunalArk4);
    MainComunalArk->push(comunalArk5);
    MainComunalArk->push(comunalArk6);
    MainComunalArk->push(comunalArk7);
    MainComunalArk->push(comunalArk8);
    MainComunalArk->push(comunalArk9);
    MainComunalArk->push(comunalArk10);
    MainComunalArk->push(comunalArk11);
    MainComunalArk->push(comunalArk12);
    MainComunalArk->push(comunalArk13);
    MainComunalArk->push(comunalArk14);
    MainComunalArk->push(comunalArk15);
    MainComunalArk->push(comunalArk16);
}

void Initialize::InitializeBoard(CircularList<Spot> *board) {
    Tax exit = *new Tax("Exit", 200);
    Property mediterraneanAvenue = *new Property("Mediterranean Avenue",Brown ,60, 2,  30, 50, Common);
    SpecialCard communalArk1 = * new SpecialCard("Communal Ark", CommunalArk);
    Property balticAvenue = *new Property("Baltic Avenue", Brown , 60, 4,  30, 50,  Common);
    Tax taxes = * new Tax("Taxes over income", 200);
    Property railRoadReading = * new Property("Railroad Reading", None, 200, 25, 100, 0,  RailRoad);
    Property orientalAvenue = * new Property("Oriental Avenue", LightBlue, 100, 6, 50, 50, Common);
    SpecialCard fortune1 = * new SpecialCard("Fortune", Fortune);
    Property vermontAvenue = * new Property("Vermont Avenue", LightBlue, 100, 6, 50, 50, Common);
    Property connecticutAvenue = * new Property("Connecticut Avenue", LightBlue, 120, 8, 60, 50, Common);
    Free visitJail = *new Free("Jail, visit only");
    Property sanCarlosSquare = * new Property("San Carlos Square", Pink, 140, 10, 70, 100, Common);
    Property electricityCompany = * new Property("Electricity Company", None, 150, 0, 75, 0, Company);
    Property statesAvenue = * new Property("States Avenue", Pink, 140, 10, 70, 100, Common);
    Property virginiaAvenue = * new Property("Virginia Avenue", Pink, 160, 12, 80, 100, Common);
    Property railRoadPennsylvania = * new Property("Railroad Pennsylvania", None, 200, 25, 100, 0,  RailRoad);
    Property stJamesSquare = * new Property("St. James Square", Orange, 180, 14, 90, 100, Common);
    SpecialCard communalArk2 = *new SpecialCard("Communal Ark", CommunalArk);
    Property tennesseeAvenue = * new Property("Tennessee Avenue", Orange, 180, 14, 90, 100, Common);
    Property newYorkAvenue = * new Property("New York Avenue", Orange, 200, 16, 100, 100, Common);
    Free freeZone = * new Free("Free zone");
    Property kentuckyAvenue = * new Property("Kentucky Avenue", Red, 220, 18, 110, 150, Common);
    SpecialCard fortune2 = * new SpecialCard("Fortune", Fortune);
    Property indianaAvenue = * new Property("Indiana Avenue", Red, 220, 18, 110, 150, Common);
    Property illinoisAvenue = * new Property("Illinois Avenue", Red, 240, 20, 120, 150, Common);
    Property railRoadBAndO = * new Property("Railroad B & O", None, 200, 25, 100, 0,  RailRoad);
    Property atlanticAvenue = * new Property("Atlantic Avenue", Yellow, 260, 22, 130, 150, Common);
    Property ventnorAvenue = * new Property("Ventnor Avenue", Yellow, 260, 22, 130, 150, Common);
    Property marvinGardens = * new Property("Marvin Gardens", Yellow, 280, 24, 140, 150, Common);
    Jail jail = *new Jail("Go to jail!!", 2);
    Property pacificAvenue = * new Property("Pacific Avenue", Green, 300, 26, 150, 200, Common);
    Property northCarolineAvenue = * new Property("North Caroline Avenue", Green, 300, 26, 150, 200, Common);
    SpecialCard communalArk3 = *new SpecialCard("Communal Ark", CommunalArk);
    Property pennsylvaniaAvenue = * new Property("Pennsylvania Avenue", Green, 320, 28, 160, 200, Common);
    Property railRoadLine = * new Property("Railroad Line", None, 200, 25, 100, 0,  RailRoad);
    SpecialCard fortune3 = * new SpecialCard("Fortune", Fortune);
    Property squaredPark = * new Property("Squared Park", Blue, 350, 35, 175, 200, Common);
    Tax luxuryTax = * new Tax("Luxury tax", 100);
    Property mayfair = * new Property("Mayfair", Blue, 400, 50, 200, 200, Common);
    board->add(exit);
    board->add(mediterraneanAvenue);
    board->add(communalArk1);
    board->add(balticAvenue);
    board->add(taxes);
    board->add(railRoadReading);
    board->add(orientalAvenue);
    board->add(fortune1);
    board->add(vermontAvenue);
    board->add(connecticutAvenue);
    board->add(visitJail);
    board->add(sanCarlosSquare);
    board->add(electricityCompany);
    board->add(statesAvenue);
    board->add(virginiaAvenue);
    board->add(railRoadPennsylvania);
    board->add(stJamesSquare);
    board->add(communalArk2);
    board->add(tennesseeAvenue);
    board->add(newYorkAvenue);
    board->add(freeZone);
    board->add(kentuckyAvenue);
    board->add(fortune2);
    board->add(indianaAvenue);
    board->add(illinoisAvenue);
    board->add(railRoadBAndO);
    board->add(atlanticAvenue);
    board->add(ventnorAvenue);
    board->add(marvinGardens);
    board->add(jail);
    board->add(pacificAvenue);
    board->add(northCarolineAvenue);
    board->add(communalArk3);
    board->add(pennsylvaniaAvenue);
    board->add(railRoadLine);
    board->add(fortune3);
    board->add(squaredPark);
    board->add(luxuryTax);
    board->add(mayfair);
}


void Initialize::InitializeGame(List<Token> *tokens, Stack<SpecialCard> *MainFortune, Stack<SpecialCard> *MainCommunalArk, CircularList<Spot> *board) {
    this->InitializeTokens(tokens);
    this->InitializeFortuneSpecialCards(MainFortune);
    this->InitializeCommunalArkSpecialCard(MainCommunalArk);
    this->InitializeBoard(board);
}