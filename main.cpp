#include <iostream>
#include "Models/SpecialCard.h"
#include "Models/Property.h"
#include "Controller/BoardController.h"
#include "Core/Node.cpp"
#include "Core/List.cpp"
#include "Core/CircularList.cpp"
#include "Core/Queue.cpp"
#include "Models/Player.cpp"
#include "Models/Tax.h"
#include "Models/Jail.h"

using namespace std;

void printPlayerInfo(Player* player) {
    cout << "=====================================" << endl;
    cout << "* " << player->getName() << "(" << player->getItem().getName() << ")" << "'s turn" << endl;
    cout << "=====================================" << endl;
    cout << "* " << "Money: " << player->getMoney() << endl;
    cout << "* " << "Current position: " << player->getSpot()->getData()->getName() << endl;
    cout << "* " << "Blocked moves: " << player->getBlockMoves() << endl;
    cout << "=====================================" << endl << endl;
}

bool idToken(int tokenId){
    if(tokenId <= 6 && to_string(tokenId) != ""){
        return true;
    }

    return false;
}

Token validToken(int id, BoardController *board){
    Token token;
    while (!idToken(id)){
        cout << "Id Invalid, you need a token to start the game" << endl;
    }

    if(idToken(id)){
        token = board->selectToken(id);
    }

    return token;
}

void spotActionRepeat(Spot *spot, Player *player, BoardController *board){
    SpotType spotType = spot->getType();

    switch (spotType) {
        case PropertyType:{
            Property *property = dynamic_cast<Property*>(spot);
            if(player->getRound() > 0 && property->getOwner() == nullptr){
                cout << "The property is available, if you want to buy it, Press(1) else Press any key" << endl;
                string answer;
                cin >> answer;

                int playerMoney = player->getMoney();
                int propertyCost = property->getCost();

                if(answer == "1" && playerMoney >= propertyCost){
                    player->setMoney(playerMoney - propertyCost);
                    property->setOwner(player);
                    cout << "Congratulations!  You bought a new property, your properties are" << endl;
                    cout << property->toString() << endl;

                }
            }else if(property->getOwner() != nullptr) {
                if(property->getOwner() != player) {
                    int rent = property->getRent();
                    cout << "You're in " << property->getOwner()->getName() << "'s property" << endl;
                    cout << "You need to pay " << rent << endl;

                    int playerMoney = player->getMoney() - rent;
                    player->setMoney(playerMoney);
                    int ownerMoney = property->getOwner()->getMoney() + rent;
                    property->getOwner()->setMoney(ownerMoney);
                }
                else {
                    //TODO: Buy a house logic
                }
            }
            break;
        }
        case TaxType:{
            Tax *tax = dynamic_cast<Tax*>(spot);
            int cost = tax->getCost();
            player->setMoney(player->getMoney() + cost);
            break;
        }
        case JailType:{
            player->setSpot(board->getJail());
            player->setBlockMoves(2);
            break;
        }
        default:
            return;
    }
}

void cardAction(SpecialCard card, Player *player, BoardController *board){
    SpecialCard specialCard = board->getActionSpecialCard(card.getCardType());
    cout << specialCard.toString() << endl;

    SpecialCardAction cardAction = specialCard.getAction();
    int amount;


    switch (cardAction) {
        case Pay:{
            amount = specialCard.getAmountToPayOrCollect();
            player->setMoney(player->getMoney() - amount);
            break;
        }

        case Collect:{
            amount = specialCard.getAmountToPayOrCollect();
            player->setMoney(player->getMoney() +  amount);
            break;
        }

        case GoTo:{
            int movements = specialCard.getPositionToGo();

            player->setSpot(board->getNewSpot(movements, player));
            spotActionRepeat(player->getSpot()->getData(), player, board);
            break;
        }

        case ExitJail:{
            int blockMoves = player->getBlockMoves();
            if(blockMoves > 0){
                player->setBlockMoves(0);
                player->getCards()->deQueue();
            }else{
                player->getCards()->enQueue(specialCard);
            }
            break;
        }

        case CalculatePay:{
            Spot *spot = player->getSpot()->getData();
            auto *property = dynamic_cast<Property*>(spot);
            int cost = property->getCost() * 2;
            Player *playerToPay = property->getOwner();
            if(playerToPay != nullptr){
                playerToPay->setMoney(playerToPay->getMoney() + cost);
                player->setMoney(player->getMoney() - cost);
            }
            break;
        }
    }

}

void spotAction(Spot *spot, Player *player, BoardController *board){
    SpotType spotType = spot->getType();

    switch (spotType) {
        case SpecialCardType:{
            SpecialCard *card = dynamic_cast<SpecialCard*>(spot);
            cardAction(*card, player, board);
            break;
        }
        case PropertyType:{
            Property *property = dynamic_cast<Property*>(spot);

            if(player->getRound() >= 0) {
                string ownerInfo = "None";

                if (property->getOwner() != nullptr) {
                    ownerInfo = property->getOwner()->getName();
                }

                cout << "======================================" << endl;
                cout << "*            Property Info           *" << endl;
                cout << "======================================" << endl;
                cout << "* " << property->getName() << endl;
                cout << "======================================" << endl;
                cout << "* Owner: " << ownerInfo << endl;
                cout << "* Rent: " << property->getRent() << endl;
                cout << "* Cost: " << property->getCost() << endl;
                cout << "======================================" << endl;
            }

            if(player->getRound() >= 0 && property->getOwner() == nullptr){
                cout << "The property is available, if you want to buy it, Press(1) else Press any key" << endl;
                string answer;
                cin >> answer;

                int playerMoney = player->getMoney();
                int propertyCost = property->getCost();

                if(answer == "1" && playerMoney >= propertyCost){
                    player->setMoney(playerMoney - propertyCost);
                    property->setOwner(player);
                    cout << "Congratulations!  You bought a new property, your properties are" << endl;
                    cout << property->toString() << endl;
                } else{
                    cout << "You lost the property " << endl;
                }

            }else if(property->getOwner() != nullptr) {
                if(property->getOwner()->getItem().getName() != player->getItem().getName()) {
                    int rent = property->getRent();
                    cout << "You're in " << property->getOwner()->getName() << "'s property" << endl;
                    cout << "You need to pay " << rent << endl;

                    int playerMoney = player->getMoney() - rent;
                    player->setMoney(playerMoney);
                    Player *owner = board->findPlayerByToken(property->getOwner()->getItem());

                    int ownerMoney = owner->getMoney() + rent;
                    owner->setMoney(ownerMoney);
                }
                else {
                    //TODO: Buy a house logic
                }
            }
            break;
        }
        case TaxType:{
            Tax *tax = dynamic_cast<Tax*>(spot);
            int cost = tax->getCost();
            player->setMoney(player->getMoney() + cost);
            break;
        }
        case JailType:{
            player->setSpot(board->getJail());
            player->setBlockMoves(2);
            break;
        }
        default:
            return;
    }
}


void playTurn(BoardController *board){
    int diceAnswer;
    int firstDice;
    int secondDice;

    Player *player = &board->getPlayerInTurns()->deQueue();
    cout << endl << endl;
    printPlayerInfo(player);

    if(player->getBlockMoves() != 0){
        cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;
        cout << "X       You are in the jail, you can't play until you leave!           X" << endl;
        cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl;

        cout << "X       if you want, you can pay 50 to leave the jail, would you like to pay it? Press(1), else press any other key           X" << endl;
        cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX" << endl << endl;

        string answerToExitJail;
        cin >> answerToExitJail;

        if(answerToExitJail == "1"){
            player->setMoney(player->getMoney() - 50);
            player->setBlockMoves(0);
        } else{
            player->setBlockMoves(player->getBlockMoves() - 1);
        }

    } else {
        string answer;
        cout << "Throw dice, press (Any key)" << endl;
        cin >> answer;

        firstDice = board->throwDice();
        secondDice = board->throwDice();
        diceAnswer = firstDice + secondDice;

        cout << "=====================================" << endl;
        cout << "* You got " << diceAnswer << "                         *" << endl;
        cout << "=====================================" << endl << endl;

        player->setSpot(board->getNewSpot(diceAnswer, player));

        Spot *spot = player->getSpot()->getData();
        spotAction(spot, player, board);
    }

    cout << "=====================================" << endl;
    cout << "* User info after turn:" << endl;
    printPlayerInfo(player);

    board->getPlayerInTurns()->enQueue(*player);
}

void finishGame(BoardController *board) {
    cout << "=====================================================================" << endl;
    cout << "* Thanks for playing! Do you want to save the game for later? (y/n) *" << endl;
    cout << "=====================================================================" << endl;
    cout << "* Enter your answer: ";

    string saveGame;
    cin >> saveGame;

    bool shouldSaveGame = saveGame == "y" || saveGame == "Y";

    if(!shouldSaveGame) {
        Player* winner = board->getWinner();
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "* The game is not going to be saved! *" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "!!!!!!!!!! CONGRATULATIONS !!!!!!!!!!!" << endl;
        cout << "* The winner is: " << winner->getName() << "(" << winner->getItem().getName() << ")" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }else {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "* The game was saved successfully! *" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    }

    board->endGame(shouldSaveGame);
}

void gameMenu(BoardController *board) {
    int option = 0;

    while(option != 3) {
        Player *player = &board->getPlayerInTurns()->getFront()->getData();

        cout << "#####################################" << endl;
        cout << "* " << player->getName() << "(" << player->getItem().getName() << ")" << " game menu" << endl;
        cout << "#####################################" << endl;
        cout << "* 1. Play your turn" << endl;
        cout << "* 2. Exit game" << endl;
        cout << "* 3. Finish the game for all players" << endl;
        cout << "#####################################" << endl;
        cout << "* Enter an option to continue: ";
        cin >> option;

        switch (option) {
            case 1:
                playTurn(board);
                break;
            case 2: {
                int totalPlayers = board->getPlayerInTurns()->getLength();

                if (totalPlayers - 1 < 2) {
                    cout << "There are not enough players to play!!" << endl;
                    finishGame(board);
                    option = 3;
                } else {
                    board->getPlayerInTurns()->deQueue();
                }

                break;
            }
            case 3:
                finishGame(board);
                break;
            default:
                cout << "No correct option selected. Try again.";
                break;
        }
    }
}

void InitTurns(BoardController *board, bool isNewGame){
    int length = board->getPlayers()->getLength();
    Node<Player> *playerNode = board->getPlayers()->getHead();
    int acum = 0;
    cout << "=====================================" << endl;

    while (acum < length){
        Player player = playerNode->getData();

        cout << "* " << player.getName() << "(" << player.getItem().getName() << ")" << endl;

        if(isNewGame) {
            board->getPlayerInTurns()->enQueue(player);
        }

        acum ++;
        playerNode = playerNode->getNext();
    }

    cout << "=====================================" << endl << endl;
    gameMenu(board);
}



void InitPlayers(int players, BoardController *board){
    CircularList<Spot*> *boardGame = board->getBoard();

    for(int i = 0; i < players; i++){
        cout << "Player " << (i+1) << "- Insert your name" << endl;
        string name;
        cin >> name;
        Node<Spot*> *spot = boardGame->getHead();
        int money = 1500;
        int blockMoves = 0;
        cout << board->getAvailableTokens() << endl;
        cout << "Choose a token ID, to play with!" << endl;
        int id;
        cin >> id;
        Token token = validToken(id, board);
        int turn = board->throwDice();

        cout << "=====================================" << endl;
        cout << "* Throwing dice to decide your turn *" << endl;
        cout << "=====================================" << endl;
        cout << "* You got " << turn << "                         *" << endl;
        cout << "=====================================" << endl << endl;

        Player player = *new Player(name, spot, money, blockMoves, token, turn);
        board->getPlayers()->addDescending(player);

    }

    cout << "We're ready to start, this is the players order:" << endl;
    InitTurns(board, true);
}

void InitGame(BoardController *board){
    cout << "How many players are going to play? (6 max)" << endl;
    int players;
    cin >> players;

    if(players > 6 || players < 2){
        cout << "The limit is six players and the minimum is two" << endl;
    } else{
        InitPlayers(players, board);
    }
}

void mainMenu() {
    auto *board = new BoardController();

    cout << "##########################" << endl;
    cout << "* Main Menu" << endl;
    cout << "##########################" << endl;
    cout << "* 1. Start new game" << endl;
    cout << "* 2. Continue game" << endl;
    cout << "* 3. See records" << endl;
    cout << "* 4. Exit" << endl;
    cout << "##########################" << endl;
    cout << "* Enter an option to continue: ";
    int option;
    cin >> option;

    switch (option) {
        case 1:
            InitGame(board);
            break;
        case 2:
            board->loadGame();
            cout << "=====================================" << endl;
            cout << "* Game loaded. These are the turns! *" << endl;


            InitTurns(board, false);
            break;
        case 3:
            cout << board->getRecords() << endl;
            break;
        case 4:
            cout << "Thanks for playing.";
            exit(0);
        default:
            cout << "No correct option selected. Leaving the game";
            exit(0);
    }
}


int main() {
    mainMenu();
}
