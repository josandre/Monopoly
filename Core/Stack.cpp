//
// Created by Jocselyn Aguilar on 6/12/22.
//

#include "Stack.h"

template<typename T>
Stack<T>::Stack(int length) {
    this->top = nullptr;
    this->length = length;
}


template<typename T>
Stack<T>::Stack() {
    this->top = nullptr;
    this->length = 0;
}

template<typename T>
T Stack<T>::pop() {
    Node<T> *aux = this->top;
    T data = aux->getData();

    if(aux != nullptr){
        this->top = this->top->getNext();
        this->top->setBack(nullptr);
        delete aux;
        this->length --;
    }

    return data;
}

template<typename T>
bool Stack<T>::isEmpty() {
    if(this->top == nullptr){
        return true;
    }

    return false;
}

template<typename T>
void Stack<T>::push(T data) {
    Node<T> *newNode = new Node<T>(data);

    if(this->top == nullptr){
        this->top = newNode;
        this->length ++;

    } else{
        newNode->setNext(this->top);
        this->top->setBack(newNode);
        this->top = newNode;
        this->length ++;
    }
}

