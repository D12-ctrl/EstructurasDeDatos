/*
    Actividad 2.2: Actividad Integral estructura de datos lineales 
    Diego Mellado Oliveros
    Eduardo Gaona

    Programación de estructura de datos y algoritmos fundamentales
*/

#include <iostream>
#include "Queu.hpp"
#include "Stack.hpp"
//temporal
#include <iostream>
#include <stdio.h>
#include <stdlib.h> /* srand, rand */
#include <time.h>   /* time */
#include <string.h>
using namespace std;

template <class T>
class Conexiones
{
public:
    string ip;
    string name;
    /*Conexiones de entrada: Pila*/
    Stack<T> *conexionesEntrada;
    /*Conexiones de salida: Cola*/
    Queu<T> *conexionesSalida;
    /*Conexiones que coinciden entrada: Pila*/
    Stack<T> *conexionesSimEntrada;
    /*Conexiones de salida: Cola*/
    Queu<T> *conexionesSimSalida;

    /*Constructores*/
    Conexiones() {}
    Conexiones(string _ip, string _name) : ip(_ip), name(_name) {}
    /*Añadir conexiones entrada*/
    void addConexionesE(const T &);
    /*Añadir conexiones salida*/
    void addConexionesS(const T &);
    /*Elementos semejantes*/
    void ReadInOut(const T &);
};

string ipRand = "";

string GenIP()
{
    int randNum;
    string str; // Generamos una variable string
    /* Inicializamos random seed: */
    srand(time(NULL));
    /* Generamos un número aleatorio entre 1 y 150 */
    randNum = rand() % 150 + 1;
    //Imprimimos la dirección IP
    cout << "Su dirección IP es la siguiente: " << endl;
    cout << "172.17.248." << randNum << endl;
    stringstream ss;
    ss << randNum;
    ss >> str;
    //Ahora str contiene nuestro número random en string que posteriormente podemos concatenar
    cout << "eL NÚM RAND en string ES: " << str << endl;
    //Concatenamos y comparamos

    ipRand = "172.17.248." + str;
    cout << ipRand << endl;

    // While para comparar los registros
    return ipRand;
}

template <class T>
void Conexiones<T>::addConexionesE(const T &value)
{
    if (value != "-")
    {
        Element<T> ip = new Element<T>(value);
        conexionesEntrada->insert(value);
    }
    if (value == ipRand)
    {
        Element<T> ip = new Element<T>(value);
        conexionesSimEntrada->insert(value);
    }
}

template <class T>
void Conexiones<T>::addConexionesS(const T &value)
{
    if (value != "-")
    {
        Element<T> ip = new Element<T>(value);
        conexionesSalida->insert(value);
    }
    if (value == ipRand)
    {
        Element<T> ip = new Element<T>(value);
        conexionesSimSalida->insert(value);
    }
}
