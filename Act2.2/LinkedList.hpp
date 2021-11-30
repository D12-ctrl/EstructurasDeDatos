#include <iostream>
#include "Element.hpp"
#include <stdio.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */

#pragma once

using namespace std;

template <class T>

class LinkedList
{
    //Primer elemento de la lista

    Element<T> *firstElmnt = nullptr;

public:
    LinkedList() {}
    virtual ~LinkedList();

    //Regresa el primer elemento de la lista
    Element<T> *firstElement();
    //Checar si la lista esta vacia
    bool emptyList();
    //Añadir un nuevo elemento a la lista
    void addSorted(Element<T> *);
    //Contar los elementos de la lista
    int Count();
    // Crear una sublista de un rango
    LinkedList<T> *Sublist(int, int);
    // Borrar un rango de elementos
    void DeleteRange(int, int);
    // Unir dos listas
    LinkedList<T> *Union(LinkedList<T> *);
    // Elementos que se encuentran en ambas listas
    LinkedList<T> *Intersection(LinkedList<T> *);
    // Elementos presentes en la lista A pero no en la B
    LinkedList<T> *Except(LinkedList<T> *);
    //Imprimir elementos
    void PrintElements();
    //friend ostream & operator<<(ostream & os, const LinkedList<T> & Element);

    ~LinkedList();
};

template <class T>
Element<T> *LinkedList<T>::firstElement()
{
    return firstElmnt;
}
template <class T>
LinkedList<T>::~LinkedList()
{
    this->clear();
}
template <class T>
bool LinkedList<T>::emptyList()
{
    return this->firstElmnt == 0;
}

template <class T>
/* Complejidad O(n) */
void LinkedList<T>::addSorted(Element<T> *elemnt)
{
    if (firstElmnt == nullptr) //Si el primer elmento esta
    {
        firstElmnt = elemnt;
        firstElmnt->setNextElement(nullptr);
    }
    else
    {
        Element<T> *temp = firstElmnt;
        while (temp->getNextElement() != nullptr)
        {
            temp = temp->getNextElement();
        }
        elemnt->setNextElement(nullptr);
        temp->setNextElement(elemnt);
    }
}

template <class T>
/*Complejidad O(n)*/
int LinkedList<T>::Count()
{
    int i = 0;
    Element<T> *temp = firstElmnt;

    while (temp != nullptr) //Mientras el siguiente elemento de la lista no sea cero
    {
        temp = temp->getNextElement(); // Seguirá avanznado
        i++;                           // El contador aumenta
    }

    return i;
}

template <class T>
/*Complejidad O(n)*/
LinkedList<T> *LinkedList<T>::Sublist(int begin, int end)
{
    //Se crea una nueva lista
    LinkedList<T> *list = new LinkedList<T>();
    // referencia al primer elemento
    Element<T> *temp = firstElmnt;
    int i = 0;
    begin = begin - 1;
    end = end - 1;

    while (temp->getNextElement() != nullptr)
    {
        if (i >= begin && i <= end)
        {
            Element<int> *newElement = new Element<int>(temp->getInfo());
            list->addSorted(newElement);
        }
        i++;
        temp = temp->getNextElement();
    }

    return list;
}

template <class T>
void LinkedList<T>::DeleteRange(int begin, int end)
{
}

template <class T>
/*Complejidad O(n)*/
LinkedList<T> *LinkedList<T>::Union(LinkedList<T> *B)
{
    //Primer elmento de la lista A
    Element<T> *temp = firstElmnt;

    //Primer elemento de la lista B
    Element<T> *firs = B->firstElmnt;

    //Crear una nueva lista
    LinkedList<T> *list = new LinkedList<T>();

    while (temp->getNextElement() != nullptr) // Se recorre la lista
    {

        Element<int> *newElement = new Element<int>(temp->getInfo());
        list->addSorted(newElement);
        temp = temp->getNextElement();
    }

    while (firs->getNextElement() != nullptr)
    {
        Element<int> *elmnt = new Element<int>(firs->getInfo());
        list->addSorted(elmnt);
        firs = firs->getNextElement();
    }

    //list->addSorted(firs);

    return list;
}

template <class T>
/*Complejidad O(n^2)*/
LinkedList<T> *LinkedList<T>::Intersection(LinkedList<T> *B)
{
    int coun = B->Count();
    //Obtiene el primer elemento de la lista A
    Element<T> *temp = firstElmnt;

    //Obtiene el primer elemento de la lista B
    Element<T> *firs = B->firstElmnt;
    int j;

    // Crea una nueva lista
    LinkedList<T> *list = new LinkedList<T>();

    while (temp->getNextElement() != nullptr)
    {

        j = 0;
        while (coun >= j)
        {
            /*Si el elemnto de la lista A y lista B son iguales
            se añade a la nueva lista*/
            if (temp->getInfo() == firs->getInfo())
            {
                Element<int> *elmnt = new Element<int>(temp->getInfo());
                list->addSorted(elmnt);
            }
            j++;
            temp = temp->getNextElement();
        }
        if (firs->getNextElement() == nullptr)
            break;
        firs = firs->getNextElement();
        temp = firstElmnt;
        temp = temp->getNextElement();
    }
case 8:
{
    cout << "Adios" << endl;
    break;
}

    return list;
}

template <class T>
/*Complejidad O(n^2)*/
LinkedList<T> *LinkedList<T>::Except(LinkedList<T> *B)
{
    int coun = B->Count();
    //Primer elemento de la lista A
    Element<T> *temp = firstElmnt;

    //Primer elemento de la lista B
    Element<T> *firs = B->firstElmnt;

    //Crear una nueva lista
    LinkedList<T> *list = new LinkedList<T>();

    while (temp->getNextElement() != nullptr)
    {
        int j = 0;
        while (coun >= j)
        {
            /*Si el elemnto de la lista A y lista B son iguales
            se añade a la nueva lista*/
            if (temp->getInfo() != firs->getInfo())
            {
                Element<int> *elmnt = new Element<int>(temp->getInfo());
                list->addSorted(elmnt);
            }
            j++;
            temp = temp->getNextElement();
        }
        if (firs->getNextElement() == nullptr)
            break;
        firs = firs->getNextElement();
        temp = firstElmnt;
        temp = temp->getNextElement();
    }
    return list;
}

template <class T>
/*Complejidad O(n)*/
void LinkedList<T>::PrintElements()
{
    Element<T> *temp = firstElmnt;
    while (temp->getNextElement() != nullptr)
    {
        temp->print();
        temp = temp->getNextElement();
    }
}
