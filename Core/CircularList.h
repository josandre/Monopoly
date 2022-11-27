//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_CIRCULARLIST_H
#define MONOPOLY_CIRCULARLIST_H
#include "./Node.h"
using namespace std;
#include "iostream"

template<typename T>
class CircularList {
public:
    explicit CircularList();
    bool add(T);
    string toString();
    T findByIndex(int);

private:
    Node<T> *head = nullptr;
    int length;

};


#endif //MONOPOLY_CIRCULARLIST_H
