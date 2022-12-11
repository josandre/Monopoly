//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_NODE_H
#define MONOPOLY_NODE_H

template <typename T>

class Node {

public:
    explicit Node(T data);

    explicit Node();

    Node<T> *getNext();

    void setNext(Node<T> *next);

    Node<T> *getBack();

    void setBack(Node<T> *back);

    T& getData();

    void setData(T);


private:
    Node<T> *next;
    Node<T> *back;
    T data;
};

#endif //MONOPOLY_NODE_H
