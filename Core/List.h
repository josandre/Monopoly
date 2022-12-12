//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_LIST_H
#define MONOPOLY_LIST_H
#include "./Node.h"

using namespace std;
#include "iostream"

template <typename T>
class List {
public:
    explicit List(int);
    explicit List();
    bool add(T);
    void addDescending(T);
    void addDescendingByMoney(T);
    string toString();
    T& findByIndex(int);
    Node<T> *getHead();
    int getMaxLength();
    int getLength();




private:
    Node<T> *head = nullptr;
    int maxLength;
    int length;
    bool isFull();
    void addBeginning(T);
};



#endif //MONOPOLY_LIST_H
