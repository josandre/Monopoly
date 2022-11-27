//
// Created by Jocselyn Aguilar on 27/11/22.
//

#ifndef MONOPOLY_QUEUE_H
#define MONOPOLY_QUEUE_H

#include "Node.h"
#include "../Models/Player.h"

template<typename T>
class Queue {
public:
    explicit Queue(int, Node<T>, Node<T>);
    explicit  Queue();
    Node<T> *getFront();
    void setFront(T *);
    Node<T> *getFinal();
    void setFinal(T *);
    void enQueue(T);
    T deQueue();
    string toString();



private:
    int length;
    Node<T> *front;
    Node<T> *final;

};


#endif //MONOPOLY_QUEUE_H
