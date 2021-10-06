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
        Elemnt<T> * last = nullptr;

    /*Metodos publicos*/

    public:
    
        //Constructor
        Queu(): LinkedList<T>(){}

        //Destructor
        virtual ~Queu();

        //Apuntador al ultimo elemento de la cola
        Element<T>* last() const;

        //Eliminar el primer elemento de la cola
        Element<T>* dequeue();

        //Eliminar la cola
        void clear() override;

        //Imprimir cola
        template <typename Tn>
        friend ostream & operator <<(ostream&, const Queu<Tn>&);

        //Metodos heredados
        using LinkedList<T>::Count();

};