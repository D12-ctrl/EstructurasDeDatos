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

        /*Constructores*/
        Conexiones(){}
        Conexiones(string _ip, string _name): ip(_ip), name(_name){}
        /*Conexiones de entrada: Pila*/
        Stack<T>* conexionesEntrada;
        /*Conexiones de salida: Cola*/
        Queu<T>* conexionesSalida;
        /*Añadir conexiones entrada*/
        void addConexionesE(const T &);
        /*Añadir conexiones salida*/
        void addConexionesS(const T &);

};

