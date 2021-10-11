/*
    Actividad 2.2: Actividad Integral estructura de datos lineales 
    Diego Mellado Oliveros
    Eduardo Gaona

    Programación de estructura de datos y algoritmos fundamentales
*/

#include<iostream>
#include "Queu.hpp"
#include "Stack.hpp"

using namespace std;

template <class T>
class Conexiones
{
    public:
        string ip;
        string name;
        /*Conexiones de entrada: Pila*/
        Stack<T>* conexionesEntrada;
        /*Conexiones de salida: Cola*/
        Queu<T>* conexionesSalida;

        /*Constructores*/
        Conexiones(){}
        Conexiones(string _ip, string _name): ip(_ip), name(_name){}
        /*Añadir conexiones entrada*/
        void addConexionesE(const T &);
        /*Añadir conexiones salida*/
        void addConexionesS(const T &);

};

template <class T>
void Conexiones<T>::addConexionesE(const T & value)
{
    if (value != "-")
    {
        Element<T> ip = new Element<T>(value);
        conexionesEntrada->insert(value);
    }
}

template <class T>
void Conexiones<T>::addConexionesS(const T & value)
{
    if(value != "-")
    {
        Element<T> ip = new Element<T>(value);
        conexionesSalida->insert(value);
    }
}