//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "BoardController.h"
#include "../Core/Node.cpp"
#include "../Core/List.cpp"
#include "../Core/Queue.cpp"
#include "../Core/Stack.cpp"
#include "../Core/CircularList.cpp"

#include "../Models/Property.h"
#include "../Controller/Initialize.h"
#include <fstream>
#include <sstream>

BoardController::BoardController() {
    this->tokens =  new List<Token>(6);
    this->players = new List<Player>();
    this->records = new List<Player>();
    this->playerTurns = new Queue<Player>();
    this->Mainfortune = new Stack<SpecialCard>();
    this->Secondfortune = new Stack<SpecialCard>();
    this->MainComunalArk = new Stack<SpecialCard>();
    this->SecondComunalArk = new Stack<SpecialCard>();
    this->board = new CircularList<Spot*>();
    Initialize initGame = *new Initialize();
    initGame.InitializeGame(this->tokens, this->Mainfortune, this->MainComunalArk, this->board, this->records);
    this->jail = this->findSpotByName("Jail");
}

Node<Spot*> *BoardController::getJail() {
    return this->jail;
}

Player* BoardController::findPlayerByToken(Token token) {
    Node<Player> *aux = this->playerTurns->getFront();

    while(aux != nullptr) {
        if(aux->getData().getItem().getName() == token.getName()) {
            return &aux->getData();
        }

        aux = aux->getNext();
    }

    return nullptr;
}

Node<Spot*> *BoardController::findSpotByName(string spotName) {
    Node<Spot*> *aux = this->board->getHead();
    bool first = true;

    while(first || aux != this->board->getHead()) {
        if(aux->getData()->getName() == spotName) {
            return aux;
        }

        aux = aux->getNext();
        first = false;
    }

    return nullptr;
}

SpecialCard BoardController::getActionSpecialCard(SpecialCardTypes type) {

    if(type == Fortune){
        SpecialCard card =  Mainfortune->pop();
        this->Secondfortune->push(card);
        if(Mainfortune->isEmpty()){
            this->Mainfortune = Secondfortune;
            this->Secondfortune = new Stack<SpecialCard>();
        }
        return card;
    }

    SpecialCard card =  MainComunalArk->pop();
    this->SecondComunalArk->push(card);
    if(MainComunalArk->isEmpty()){
        this->MainComunalArk = SecondComunalArk;
        this->SecondComunalArk = new Stack<SpecialCard>();
    }
    return card;

}

List<Player> *BoardController::getPlayers() {
    return this->players;
}


Node<Spot*> *BoardController::getNewSpot(int movements, Player *player) {
    Node<Spot*> *aux = player->getSpot();
    for(int i = 0; i < movements; i++){
        aux = aux->getNext();

        if(aux->getData()->getName() == "Exit") {
            auto money = player->getMoney() + 200;
            player->setMoney(money);
            player->setRound();
        }
    }

    return aux;
}

Queue<Player> *BoardController::getPlayerInTurns() {
    return this->playerTurns;
}


CircularList<Spot*> *BoardController::getBoard() {
    return this->board;
}

string BoardController::getAvailableTokens() {
    Node<Token> *aux = this->tokens->getHead();
    string result = "";
    while (aux != nullptr){
        if(!aux->getData().getInUse()){
            result +=  aux->getData().toString();
            result += "\n ---------------------------------------\n";
        }

        aux = aux->getNext();
    }

    result += "";
    return result;
}

string  BoardController::getPlayersReady() {
    Node<Player> *aux = this->playerTurns->getFront();
    string result = "";
    while (aux != nullptr){
        result += aux->getData().toString();
        result += "\n --------------------------------------------------------------------------------------------------------\n";
        aux = aux->getNext();
    }
    result += "";
    return result;
}

Token BoardController::selectToken(int idSelected) {
    Token *token = &this->tokens->findByIndex(idSelected-1);

    if(token->getId() == idSelected && token->getInUse() == false) {
        token->setInUse(true);
    }

    return *token;
}

int BoardController::throwDice() {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_real_distribution<double> dist(1, 6);
    return (int)dist(mt);
}

Player* BoardController::getWinner() {
    Node<Player> *aux = this->playerTurns->getFront();
    Player *winner = nullptr;

    while(aux != nullptr) {
        if(winner == nullptr || aux->getData().getMoney() > winner->getMoney()) {
           winner = &aux->getData();
        }

        aux = aux->getNext();
    }

    return winner;
}

string BoardController::getRecords() {
    string result = "************************\n";
    result += "*     TOP RECORDS      *\n";
    result += "************************\n";

    Node<Player> *record = records->getHead();
    int count = 1;
    while(record != nullptr) {
        Player player = record->getData();
        result += "* " + to_string(count) + ". ";
        result += player.getName() + " with $" + to_string(player.getMoney()) + "\n";

        count++;
        record = record->getNext();
    }

    return result;
}

void BoardController::saveRecords() {
    while(this->playerTurns->getLength() > 0) {
        Player* player = &this->playerTurns->deQueue();
        records->addDescendingByMoney(*player);
    }

    // Saving records
    ofstream RecordsFile("records.csv");
    int cont = 0;
    Node<Player> *aux = records->getHead();

    while(aux != nullptr && cont < 3) {
        RecordsFile << aux->getData().toCsv() << endl;
        aux = aux->getNext();
        cont++;
    }

    RecordsFile.close();
}

void BoardController::loadGame() {
    this->loadPlayersState();
    this->loadGameBoardState();
}

void BoardController::loadPlayersState() {
    string line;
    ifstream RecordsFile("saved-players.csv");
    vector<string> row;

    while (getline (RecordsFile, line)) {
        row.clear();
        stringstream str(line);
        string column;

        //Name,Token,Money,BlockMoves,Spot
        while (getline(str, column, ',')) {
            row.push_back(column);
        }

        string name = row[0];
        Token *token = new Token(1, row[1]);
        int money = stoi(row[2]);
        int blockMoves = stoi(row[3]);
        Node<Spot*> *spot = this->findSpotByName(row[4]);

        Player player = *new Player(name, spot, money, blockMoves, *token, 0);
        this->players->add(player);
        this->playerTurns->enQueue(player);
    }

    RecordsFile.close();
}

void BoardController::loadGameBoardState() {
    string line;
    ifstream RecordsFile("saved-game-board.csv");
    vector<string> row;

    while (getline (RecordsFile, line)) {
        row.clear();
        stringstream str(line);
        string column;

        //Name,Type,Owner
        while (getline(str, column, ',')) {
            row.push_back(column);
        }

        string name = row[0];

        if(row.size() == 3) {
            Spot *spot = this->findSpotByName(name)->getData();
            Token token = *new Token(1, row[2]);

            Player* owner = this->findPlayerByToken(token);
            Property *property = dynamic_cast<Property*>(spot);
            property->setOwner(owner);
        }
    }

    RecordsFile.close();
}

void BoardController::saveGame() {
    this->savePlayersState();
    this->saveGameBoardState();
}

void BoardController::savePlayersState() {
    // Saving records
    ofstream RecordsFile("saved-players.csv");
    Node<Player> *aux = playerTurns->getFront();

    while(aux != nullptr) {
        RecordsFile << aux->getData().toCsv() << endl;
        aux = aux->getNext();
    }

    RecordsFile.close();
}

void BoardController::saveGameBoardState() {
    // Saving records
    ofstream RecordsFile("saved-game-board.csv");
    Node<Spot*> *aux = board->getHead();
    bool first = true;

    while(first || aux != this->board->getHead()) {
        Spot *spot = aux->getData();
        string spotRecord = spot->toCsv();

        if(spot->getType() == PropertyType) {
            Property *property = dynamic_cast<Property*>(spot);
            spotRecord = property->getOwner() != nullptr ?
                    (spotRecord + "," + property->getOwner()->getItem().getName()) :
                         spotRecord;
        }

        RecordsFile << spotRecord << endl;
        aux = aux->getNext();
        first = false;
    }

    RecordsFile.close();
}

void BoardController::endGame(bool saveGame) {
    if(saveGame) {
        this->saveGame();
    }
    else{
        this->saveRecords();
    }
}