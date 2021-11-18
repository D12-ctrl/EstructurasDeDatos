/*

Actividad 4.2: actividad integral de grafos
Diego Mellado Oliveros


18 de noviembre 2021

*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

#include "Registros.hpp"
#include "Graph.hpp"

using namespace std;

auto read_csv(string filename)
{
    /*Crear un vector */
    vector<Register> lines;

    /*Leer el archivo*/
    ifstream file(filename);

    string line; // Variable that storage every line

    /* Read the data line by line*/

    while(getline(file, line))
    {
        stringstream ss(line);

        //Variables for every field
            string date;
            string hour;
            string oIP;
            string oPort;
            string oName;
            string dPort;
            string dIP;
            string dName;
/*Fecha, Hora, IP Origen, Puerto Origen, Nombre Origen, IP Destino, Puerto Destino, Nombre Destino*/
        getline(ss, date, ',');
        getline(ss, hour, ',');
        getline(ss, oIP, ',');
        getline(ss, oPort, ',');
        getline(ss, oName, ',');
        getline(ss, dIP, ',');
        getline(ss, dPort, ',');
        getline(ss, dName);

        
        Register registr = Register(date, hour, oName, oIP, oPort, dName, dIP, dPort);
        lines.push_back(registr);
    }

    file.close();

    return lines;
}

auto internalIP(vector<Register> registros)
{
    /*Crear un nuevo vector donde se almacenaran las IP*/
    vector<Register> logs;

    /*Iterar sobre el vector*/
    for(auto element : registros)
    {
        /*Si la IP es una IP interna entonces la agrega al vector*/
        if(element.getDestinationIP() == "172.17.248.178") 
        {
            
            logs.push_back(element);
        }
    }

    return logs;
}

auto websites(vector<Register> registros)
{   
    /*Crear un vector donde se almacenan los sitios web*/
    vector<Register> logs;

    /*Iterar sobre vector*/
    for(auto element : registros)
    {   
        /*Si el sitio web de destino no es un nulo lo agrega al vector*/
        if(element.getDestination() != "-")
        {
            logs.push_back(element);
        }

    }

    return logs;
}

auto grafoRedInter(vector<Register> internalIPdata)
{
    
}
int main()
{   
    /*Vector principal de datos*/
    vector<Register> registros = read_csv("equipo14.csv");

    /*Vector de datos de la IP interna*/
    vector<Register> interalIPdata = internalIP(registros);

    /*Vector de datos de sitios web*/
    vector<Register> websitesData = websites(registros);

}

