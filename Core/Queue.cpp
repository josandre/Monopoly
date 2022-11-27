//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "Queue.h"
template<typename T>
Queue<T>::Queue(int length, Node<T> front, Node<T> final) {
    this->length = length;
    this->front = front;
     this->final = final;

}

template<typename T>
Queue<T>::Queue() {}

template<typename T>
Node<T> *Queue<T>::getFront(){
    return this->front;
}

template<typename T>
void Queue<T>::setFront(T *newFront) {
    this->front = newFront;
}

template<typename T>
Node<T> *Queue<T>::getFinal() {
    return  this->final;
}

template<typename T>
void Queue<T>::setFinal(T *newFinal) {
    this->final = newFinal;
}

template<typename T>
void Queue<T>::enQueue(T data) {
    Node<T> *nuevo = new Node<T>(data);
    if(this->front == nullptr){
        this->front = nuevo;
        this->final = nuevo;

    } else{
        this->final->setNext(nuevo);
        nuevo->setBack(this->final);
        this->final = nuevo;

    }
}

template<typename T>
string Queue<T>::toString() {
    Node<T> *aux = this->front;
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
T Queue<T>::deQueue() {
    Node<T> *aux = this->front;
    if(aux != nullptr){
        this->front = aux->getNext();
        T data = aux->getData();
        delete aux;
        return data;
    }
}



