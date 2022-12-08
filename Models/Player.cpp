//
// Created by Jocselyn Aguilar on 25/11/22.
//
#include "../Core/Node.cpp"
#include "Player.h"




Player::Player(string name, Node<Spot> *spot, int money, int blockMoves, Token item, int turn) {

    this->name = name;
    this->spot = spot;
    this->money = money;
    this->blockMoves = blockMoves;
    this->item = item;
    this->turn = turn;
}

Player::Player() {};

string  Player::getName() {
    return this->name;
}

Node<Spot> *Player::getSpot() {
    return this->spot;
}

Token Player::getItem() {
    return this->item;
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



int Player::getTurn() {
    return this->turn;
}

void Player::setTurn(int turn) {
    this->turn = turn;
}

string Player::toString() {
    return "Name: " + this->name + " Turn: " + to_string(this->turn) + " Position: " + this->spot->getData().getName() +
    "Money: " + to_string(this->money) + "Item: " + this->item.toString();
}