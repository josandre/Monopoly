//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_ITEM_H
#define MONOPOLY_ITEM_H
#include <iostream>
using namespace std;

class Item {
public:
    explicit Item(int id, string name, bool inUse);
    explicit Item();
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


#endif //MONOPOLY_ITEM_H
