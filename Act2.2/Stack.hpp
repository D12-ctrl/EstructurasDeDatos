/*
    Act 2.2

    Stack.hpp
*/
#include <iostream>
#include "LinkedList.hpp"

using namespace std;

template <class T>

class Stack : private LinkedList<T>
{
    /*Metodos publicos*/

    public:
        //Constructor
        Stack(): LinkedList<T>(){}

        //Destructor
        virtual ~Stack(){};

       
        Element<T> * top() const;
        Element<T> * pop();

       
        void insert(const T &);

        /*Imprimit pila*/
        template <typename Tn>
        friend ostream & operator <<(ostream &, const Stack<Tn> &);

        /*Metodos heredados*/
        using LinkedList<T>::emptyList();
        using LinkedList<T>::Count();
};

template <class T>
/*Obtener el elemento que esta en la parte superior
Complejidad constante*/
Element<T>* Stack<T>::top() const
{
    return this->firstElmnt();
}
/*Eliminar el primer elemento de la pila
Complejidad constante*/
template <class T>
Element<T> * Stack<T>::pop()
{
    
}

/*Insertar un elemento en la lista
Complejidad lineal*/
template <class T>
void Stack<T>::insert(const T & value)
{   
    int pos = 0;
    Element<T> * elmnt = new Element<T>(value);

    if(this->emptyList() || position <= 0)
    {
        elmnt->setNextElement(this->firstElmnt);
        this->firstElmnt = elmnt;
    }
}

