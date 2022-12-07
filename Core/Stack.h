//
// Created by Jocselyn Aguilar on 6/12/22.
//

#ifndef MONOPOLY_STACK_H
#define MONOPOLY_STACK_H

#include "./Node.h"
#include "iostream"

template<typename T>
class Stack {
public:
    explicit Stack( int);
    explicit Stack();
    T pop();
    void push(T);
    bool isEmpty();

private:
    Node<T> *top = nullptr;
    int length;


};


#endif //MONOPOLY_STACK_H
