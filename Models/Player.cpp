//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "Player.h"
Player::Player() {};

Player::Player(int id, std::string name, int position, int money, int blockMoves, Token item, int turn) {
    this->id = id;
    this->name = name;
    this->position = position;
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

int Player::getPosition() {
    return this->position;
}

void Player::setPosition(int position) {
    this->position = position;
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
    return "Name: " + this->name + "Position: " + to_string(this->position) +
    "Money: " + to_string(this->money) + "Item: " + this->item.toString();
}