/*


ConexionesComputadoras.hpp
Actividad5.2

*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include "Registros.hpp"

#pragma once

class ConexionesComputadoras
{
    protected:

        std::string ip;
        std::string name;
        /*Conexiones entrantes: pila*/
        std::stack<std::string> conexionesEntrada;
        /*Conexiones salida: cola*/
        std::queue<std::string> conexionesSalida;

    public:
        /*Constructor*/
        ConexionesComputadoras(){}
        ConexionesComputadoras(std::string _ip, std::string _name) : ip(_ip), name(_name){}
        /*Setter y getter IP*/
        void setIP(std::string);
        std::string getIP();
        
        /*Setter y getter name*/
        void setName(std::string);
        std::string getName();

        /*Agregar conexiones*/
        void agregarConexionesEntrada(std::vector<Register>);
        void agregarConexionesSalida(std::vector<Register>);

        /*Regresar conjunto de datos*/
        std::stack<std::string> ConexionesEntrada();
        std::queue<std::string> ConexionesSalida();

};

void ConexionesComputadoras::setIP(std::string _ip)
{
    ip = _ip;
}

std::string ConexionesComputadoras::getIP()
{
    return ip;
}

void ConexionesComputadoras::setName(std::string _name)
{
    name = _name;
}

std::string ConexionesComputadoras::getName()
{
    return name;
}

void ConexionesComputadoras::agregarConexionesEntrada(std::vector<Register> registros)
{
    /*Recorrer el vector de registros*/
    for (auto data : registros)
    {
        if(data.getDestinationIP() == ip)
        {
            conexionesEntrada.push(data.getOriginIP());
        }
    }
    
}

void ConexionesComputadoras::agregarConexionesSalida(std::vector<Register> registros)
{
    /*Recorrer el vector*/

    for(auto data : registros)
    {
        if(data.getOriginIP() == ip)
        {
            conexionesSalida.push(data.getDestinationIP());
        }
    }
}

std::stack<std::string> ConexionesComputadoras::ConexionesEntrada()
{
    return conexionesEntrada;
}

std::queue<std::string> ConexionesComputadoras::ConexionesSalida()
{
    return conexionesSalida;
}