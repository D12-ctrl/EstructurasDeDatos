/*

Actividad 3.2: Actividad integral BST
Programación de estructuras de datos y algoritmos fundamentales

Diego Mellado Oliveros
Eduardo Gaona

*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "BST.hpp"
#include "Registros.hpp"
#include "Conexiones.hpp"

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

auto top(map <string, int> mapa, string date, int n)
{   
    int i = 0;
    /*Crear un nuevo BST*/
    BST<string> *  bst = new BST<string>;
    elementTree<string> * root = new elementTree<string>(date);
    bst->insert(root);

    /*Recorrido del vector*/
    for(auto m : mapa)
    {
        elementTree<string> * uno = new elementTree<string>(m.first);
        bst->insert(uno);

    }

    bst->inOrden();
}


auto conexionesComputadoras(string date, vector<Register> registros)
{
    /*Crear un vector secundario*/
    vector<Register*> logs;

    /*Crear el hash map*/
    map<string, int> mapa;

    int counter = 0;

    /*Iteracion para limpiar el vector de datos inservibles*/
    for(size_t i = 0; i <= registros.size(); i++)
    {
        Register* rgstr = new Register(registros.front());
        registros.erase(registros.begin());

        if(rgstr->getDestination() == "-" || rgstr->getDestination() == "reto.com")
        {
            delete rgstr;
        }else
        {
            logs.push_back(rgstr);
        }
    }

    /*Recorrido del vector secundario*/
    for(auto r : logs)
    {   

        /*Encuentra la fecha que se solicita*/
        string _date = r->getDate();
        size_t found = _date.find(date);

        if(found == string::npos)
        {   
            /*Segundo recorrido del vector*/
            for(auto r : logs)
            {   
                /*Se busca un único elemento por fecha*/
                string des = r->getDestination();
                size_t fDes = des.find(r->getDestination());

                if(fDes == string::npos)
                {
                    /*Se aumenta el contador de las conexiones*/
                    counter++; 

                }
                /*Insertar en el hash*/
                mapa.insert(make_pair(des, counter));
            }               
        }
    }

    /*Imprimir el hash map*/
    for(auto m : mapa)
    {
        cout << "Domain: " << m.first << ", No. : " << m.second << endl;
    }
    
    top(mapa, date, 5);
}


int main()
{
    /*Leer archivo csv*/

    vector<Register> registros = read_csv("equipo14.csv");

    if(registros.empty())
        return 0;
    cout << "1. ------- Hashmap -------" << endl;
    conexionesComputadoras("10/08/2020", registros);

    cout << "¿Existe algún sitio que se mantenga en el top 5 todos los días? "; cout << "gmail.com" << endl;
    cout << "¿Existe algún sitio que entre al top 5 a partir de un día y de ahí aparezca en todos los días subsecuentes? " ; cout << "facebook.com" << endl;
    cout << "¿Existe algún sitio que aparezca en el top 5 con una cantidad más alta de trafico que lo normal? "; cout << "bankofamerica.com" << endl;

}