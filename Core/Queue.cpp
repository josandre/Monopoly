//
// Created by Jocselyn Aguilar on 27/11/22.
//

#include "Queue.h"
template<typename T>
Queue<T>::Queue(int maxLength) {
    this->maxLenght = maxLength;
    this->length = 0;
    this->front = nullptr;

}

template<typename T>
Queue<T>::Queue() {
    this->front = nullptr;
    this->maxLenght = -1;
    this->length = 0;
}

template<typename T>
Node<T> *Queue<T>::getFront(){
    return this->front;
}


template<typename T>
int Queue<T>::getLength() {
    return this->length;
}

template<typename T>
int Queue<T>::getMaxLength() {
    return this->maxLenght;
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

    this->length ++;
}

template<typename T>
bool Queue<T>::isFull() {
    return this->maxLenght != -1 && this->length >= this->maxLenght;
}


template<typename T>
string Queue<T>::toString() {
    Node<T> *aux = this->front;
    string result = "[";
    while (aux != nullptr){

        result +=  aux->getData().toString();
        aux = aux->getNext();
        if(aux != nullptr){
            result += ", ";
        }


    }
    result += "]";
    return result;
}


template<typename T>
T& Queue<T>::deQueue() {
    Node<T> *aux = this->front;
    if(aux != nullptr){
        this->front = aux->getNext();
        T& data = aux->getData();
        delete aux;
        return data;
    }

    this->length --;
}



