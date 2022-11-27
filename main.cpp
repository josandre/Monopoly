#include <iostream>
#include "Core/Node.h"
#include "Models/Property.h"
#include "Models/SpecialCard.h"
#include "Controller/BoardController.h"
#include "Models/Player.cpp"
#include "Core/List.cpp"

using namespace std;

int main() {
   //Property prop = *new Property("Avenida mediterraneo", Brown, 60, 2, 30, 50, 50, 33);
   //auto specialCard = *new SpecialCard("Exit jail free", "Use this card to exit jail for free", 0, 0 , ExitJail);
    //BoardController board = *new BoardController();
    //board.initializeTokens();

    auto token = *new Token(1, "Car");
    auto player1 = *new Player(1, "Anthony", 0, 1500, 0, token, 5);
    auto player2 = *new Player(1, "Jos", 0, 1500, 0, token, 1);
    auto player3 = *new Player(1, "Cami", 0, 1500, 0, token, 6);
    auto player4 = *new Player(1, "Vayo", 0, 1500, 0, token, 4);

    auto players = new List<Player>();
    players->addDescending(player1);
    players->addDescending(player2);
    players->addDescending(player3);
    players->addDescending(player4);

    auto *aux = players->getHead();

    while(aux != nullptr) {
        cout << aux->getData().toString() << endl;
        aux = aux->getNext();
    }

    return 0;
}
