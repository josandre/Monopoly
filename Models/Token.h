//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_TOKEN_H
#define MONOPOLY_TOKEN_H
#include <iostream>
using namespace std;

class Token {
public:
    explicit Token(int id, string name);
    explicit Token();
    string toString();
    int getId();
    string getName();
    bool getInUse();
    bool setInUse(bool);
private:
    int id;
    string name;
    bool inUse;
};


#endif //MONOPOLY_TOKEN_H
