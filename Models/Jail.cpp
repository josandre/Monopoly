//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "Jail.h"
Jail::Jail(string name, int blockMoves) : Spot(name, JailType) {
    this->blockMoves = blockMoves;
}

int Jail::getBlockMoves() {
    return this->blockMoves;
}

void Jail::setBlockMoves(int blockMoves) {
    this->blockMoves = blockMoves;
}