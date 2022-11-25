//
// Created by Jocselyn Aguilar on 25/11/22.
//

#ifndef MONOPOLY_NODO_H
#define MONOPOLY_NODO_H



template <class T>
class Nodo{

public:
    explicit Nodo(T data);

    explicit Nodo();

    Nodo<T> *getNext();

    void setNext(Nodo<T> *next);

    Nodo<T> *getBack();

    void setBack(Nodo<T> *back);

    T *getData();

    void setData(T);


private:
    Nodo<T> *next;
    Nodo<T> *back;
    T data;
};


#endif //MONOPOLY_NODO_H
