//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "../Core/Node.cpp"
#include "Player.h"
Player::Player() {};

Player::Player(int id, std::string name, Node<Spot> *spot, int money, int blockMoves, Token item, int turn) {
    this->id = id;
    this->name = name;
    this->spot = spot;
    this->money = money;
    this->blockMoves = blockMoves;
    this->item = item;
    this->turn = turn;
}

int Player::getId() {
    return this->id;
}

string  Player::getName() {
    return this->name;
}

Node<Spot> *Player::getSpot() {
    return this->spot;
}

void Player::setSpot(Node<Spot> *spot) {
    this->spot = spot;
}

int Player::getMoney() {
    return this->money;
}

void Player::setMoney(int money) {
    this->money = money;
}

int Player::getBlockMoves() {
    return this->blockMoves;
}

void Player::setBlockMoves(int blockMoves) {
    this->blockMoves = blockMoves;
}

Token Player::getItem() {
    return this->item;
}

int Player::getTurn() {
    return this->turn;
}

void Player::setTurn(int turn) {
    this->turn = turn;
}

string Player::toString() {
    return "Name: " + this->name + "Position: " + this->spot->getData().getName() +
    "Money: " + to_string(this->money) + "Item: " + this->item.toString();
}