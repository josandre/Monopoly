//
// Created by Jocselyn Aguilar on 25/11/22.
//

#include "List.h"
#include "./Node.cpp"

template<typename T>
List<T>::List(int maxLength)  {
    this->head = nullptr;
    this->maxLength = maxLength;
    this->length = 0;
}

template<typename T>
List<T>::List() {
    this->head = nullptr;
    this->maxLength = -1;
    this->length = 0;
}

template<typename T>
bool List<T>::isFull() {
    return this->maxLength != -1 && this->length >= maxLength;
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

        newNode->setBack(aux);
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
Node<T> *List<T>::getHead() {
    return this->head;
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

template<typename T>
void List<T>::addBeginning(T data) {
    Node<T> *nuevo = new Node<T>(data);

    if(this->head == nullptr){
        this->head = nuevo;
    } else{
        nuevo->setNext(this->head);
        this->head->setBack(nuevo);
        this->head = nuevo;
    }
}

template<typename T>
void List<T>::addDescending(T data) {
    Node<T> *nuevoNodo = new Node<T>(data);
    Node<T> *aux = this->head;

    if(this->head == nullptr){
        this->head = nuevoNodo;
    } else{
        while(aux != nullptr){
            Node<T> *anterior = aux;
            Node<T> *siguiente = anterior->getNext();

            if(nuevoNodo->getData().getTurn() > this->head->getData().getTurn()){
                addBeginning(data);
                break;
            } else{
                if(aux->getNext() == nullptr){
                    this->add(data);
                    break;
                } else{
                    if(anterior->getData().getTurn() > nuevoNodo->getData().getTurn() &&
                        siguiente->getData().getTurn() < nuevoNodo->getData().getTurn()){
                        nuevoNodo->setNext(siguiente);
                        siguiente->setBack(nuevoNodo);
                        nuevoNodo->setBack(anterior);
                        anterior->setNext(nuevoNodo);
                        break;
                    }
                }
            }
            aux = aux->getNext();
        }
    }
}

