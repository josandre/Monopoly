//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "Nodo.h"

Nodo::Nodo(T data) {
    this->data = data;
    this->next = nullptr;
    this->back = nullptr;
}

Nodo<T> *Nodo::getNext()  {
    return this->next;
}

void Nodo::setNext(T data) {
    this->next = data;
}

Nodo<T> *Nodo::getBack()  {
    return this->back;
}

void Nodo::setBack(T data) {
    this->back = data;
}

