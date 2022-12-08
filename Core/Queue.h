//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_QUEUE_H
#define MONOPOLY_QUEUE_H

#include "./Node.h"
using namespace std;
#include "iostream"
//#include "../Models/Player.h"

template<typename T>
class Queue {
public:
    explicit Queue(int);
    explicit  Queue();
    Node<T> *getFront();
    int getMaxLength();
    int getLength();
    void enQueue(T);
    T& deQueue();
    string toString();



private:
    int length;
    int maxLenght;
    Node<T> *front;
    Node<T> *final;
    bool isFull();

};


#endif //MONOPOLY_QUEUE_H
