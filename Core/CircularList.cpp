//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "CircularList.h"


template<typename T>
CircularList<T>::CircularList() {
}

template<typename T>
bool CircularList<T>::add(T data) {
    Node<T> *newNode = new Node<T>(data);
    Node<T> *aux = this->head;

    if(this->head == nullptr){
        this->head = newNode;

    }else{
        while (aux->getNext() != nullptr){
            aux = aux->getNext();
        }

        newNode->setNext(this->head);
        this->head->setBack(newNode);
        aux->setNext(newNode);
    }

    this->length++;
    return true;
}

template<typename T>
string CircularList<T>::toString() {
    Node<T> *aux = this->head;
    string result = "[";
    int acum = 0;
    while (acum <= this->length){
        result +=  aux->getData()->toString();
        aux = aux->getNext();
        if(length != acum){
            result += ", ";
        }
        acum ++;

    }

    result += "]";
    return result;
}

template<typename T>
T CircularList<T>::findByIndex(int index) {
    Node<T> *aux = this->head;
    int count = 0;

    while (aux != nullptr){
        if(index == count){
            return aux->getData();
        }

        aux = aux->getNext();
        count++;
    }

    return nullptr;
}


