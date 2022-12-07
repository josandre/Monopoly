//
// Created by Jocselyn Aguilar on 25/11/22.
//


#include "Node.h"
template<typename T>
Node<T>::Node(T data)
{
    this->data = data;
    this->next = nullptr;
    this->back = nullptr;
}

template<typename T>
T Node<T>::getData() {
    return this->data;
}

template<typename T>
Node<T> *Node<T>::getNext() {
    return this->next;
}

template<typename T>
void Node<T>::setNext(Node<T> *next) {
    this->next = next;
}


template<typename T>
Node<T> *Node<T>::getBack() {
    return this->back;
}

template<typename T>
void Node<T>::setBack(Node<T> *back) {
    this->back = back;
}

