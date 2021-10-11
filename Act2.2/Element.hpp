/*
ITESM

    Element.hpp
    Actividad 2.1


    Diego Mellado Oliveros
    Eduardo Gaona Romero
*/

#include <iostream>
#include <string>

#pragma once

using namespace std;

template <class T>
class Element
{
protected:
    T information;
    Element<T> *next = nullptr;

public:
    //Constructores
    Element() {}
    Element(const T &info) : information(info) {}

    //Destructor
    //virtual ~Element();

    //Setter and getters
    Element<T> *getNextElement() const { return next; }
    void setNextElement(Element<T> *elemnt) { next = elemnt; }
    void print() { cout << information << endl; }
    T getInfo() const { return information; }
};
