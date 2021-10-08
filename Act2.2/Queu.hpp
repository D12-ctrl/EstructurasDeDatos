/*
    Act 2.2

    Queu.hpp
*/

#include <iostream>
#include "LinkedList.hpp"

using namespace std;

template <class T>
class Queu : private LinkedList<T>
{
    /*Metodos privados*/

    private:
        Element<T> * last_ = nullptr;

    /*Metodos publicos*/

    public:
    
        //Constructor
        Queu(): LinkedList<T>(){}

        //Destructor
        virtual ~Queu();

        //Apuntador al ultimo elemento de la cola
        Element<T>* last() const;

        //Insertar elemento en la cola
        void insert(const T &);

        //Eliminar el primer elemento de la cola
        Element<T>* dequeue();

        //Eliminar la cola
        void clear() override;

        //Imprimir cola
        template <typename Tn>
        friend ostream & operator <<(ostream&, const Queu<Tn>&);

        //Metodos heredados
        using LinkedList<T>::Count();
        using LinkedList<T>::firstElement();
        using LinkedList<T>::emptyList();

};

template <class T>
 Queu<T>::~Queu()
{
    this->clear;
}

/*Complejidad constante*/
template <class T>
Element<T> * Queu<T>::last() const
{
    return this-> last_ ;
}

/*Complejidad lineal*/
template <class T>
void Queu<T>::insert(const T & value)
{   
    Element<T> * elmnt = new Element<T>(value);

    if(this->emptyList())
    {
        this->last_ = this->firstElement = elmnt;
    }
    else
    {
        this->last_->setNextElement(elmnt);
        this->last_ = elmnt;
    }
}

template <class T>
void Queu<T>::clear()
{
    LinkedList<T>::clear();

        //Ultimo elemento apuntando a null
        this->last_ = nullptr;
    
}