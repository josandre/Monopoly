//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "List.h"

template<typename T>
List<T>::List( int maxLength)  {
    this->head = nullptr;
    this->maxLength = maxLength;
    this->length = 0;
}

template<typename T>
List<T>::List() {
    this->head = nullptr;
    this->maxLength = nullptr;
    this->length = 0;
}

template<typename T>
bool List<T>::isFull() {
    return this->maxLength != nullptr || this->length >= maxLength;
}

template<typename T>
bool List<T>::add(T data) {
    Node<T> *newNode = new Node<T>(data);
    Node<T> *aux = this->head;

    if(isFull()){
        return false;
    }

    if(this->head == nullptr){
        this->head = newNode;
    }else{
        while (aux->getNext() != nullptr){
            aux = aux->getNext();
        }

        aux->setNext(newNode);
    }

    this->length++;
    return true;
}

template<typename T>
string List<T>::toString() {
    Node<T> *aux = this->head;
    string result = "[";
    while (aux != nullptr){
        result +=  aux->getData()->toString();
        aux = aux->getNext();
        if(aux != nullptr){
            result += ", ";
        }

    }

    result += "]";
    return result;
}

template<typename T>
T List<T>::findByIndex(int position) {
    Node<T> *aux = this->head;
    int count = 0;

    while (aux != nullptr){
        if(position == count){
            return aux->getData();
        }

        aux = aux->getNext();
        count++;
    }

    return nullptr;
}
