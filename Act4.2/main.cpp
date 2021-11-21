/*

Actividad 4.2: actividad integral de grafos
Diego Mellado Oliveros


18 de noviembre 2021

*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>

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

auto conectionsTointernal(vector<Register> registros)
{
    vector<Register> logs;

    for(auto element : registros)
    {
        if(element.getOriginIP() == "172.17.248.178") 
        {
            logs.push_back(element);
        }
    }

    if(!logs.empty())
    {
        return logs;
    } else {
         cout << "No se encuentran datos" << endl;
    }
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
{   int counter;
    int i = 0;
    /*Estructura stl no añade datos repetidos*/
    set<string> dates;

    /*Crear un grafo nuevo*/
    Graph<string, int> * redInterna = new Graph<string, int>;

    Vertex<string, int> * A = new Vertex<string, int>("Redes internas");

    redInterna->addVertex(A);

    /*Iterar sobre el vector de datos*/
    for (auto log : internalIPdata)
    {   /*Añadir las fechas al set*/
        dates.insert(log.getDate());
    }

    for (auto date : dates)
    {   
        /*Crear un nuevo vertice con la fecha*/

        Vertex<string, int> * fecha = new Vertex<string, int>(date);

        /*Añadir el vertice al grafo*/
        redInterna->addVertex(fecha);

        counter = 1;
         
        while(counter > 0)
        {
            if(date == internalIPdata[i].getDate())
            {   
                counter++;
                i++;
                
                if(i == internalIPdata.size())
                {   counter --;
                    redInterna->addEdge(A, fecha, counter);
                    break;
                }
            }
            else             
            {
                counter --;
               redInterna->addEdge(A, fecha, counter);
                break;
            }
            
        }
    }
    
    return redInterna;
    
}

auto conectiosToB(vector<Register> websitesData)
{   
    /*Crear grafo para guardar las conexiones*/
    Graph<string, int> * websites = new Graph<string, int>;

    /*Vector para guardar sitios*/
    vector<Register> sites;

    /*Vertice principal*/
    Vertex<string, int> * B = new Vertex<string, int>("Conexiones a B");

    /*Añadir vertice*/
    websites->addVertex(B);

    for(auto site : websitesData)
    {
        
        /*Guardar el sitio web*/
        string name = site.getDestination();
        
        if(name.length() > 20)
        {
            sites.push_back(site);
        }
    }

    
    int cont = 0;
        
    Vertex<string, int> * date = new Vertex<string, int>(sites[1].getDate());

    websites->addVertex(date);
        
    for(int i = 0; i < sites.size(); i++)
    {
        if(sites[1].getDate() == sites[i].getDate())
        {
            if(sites[1].getDestination() == sites[i].getDestination())
            {
                cont++;
            }
        }
    }

    cout << "Sitio web " << sites[1].getDestination() << endl;

    websites->addEdge(B, date, cont);

    return websites;
}

auto conectionsToC(vector<Register> websiteData)
{
    Graph<string, int> * conexionesC = new Graph<string, int>;

    set<string> dates;
    set<string> websites;

    Vertex<string, int> * C = new Vertex<string, int>("Conexiones a C");
    conexionesC->addVertex(C);

    for(auto site : websiteData)
    {
        dates.insert(site.getDate());
        websites.insert(site.getDestination());
    }

    vector<string> websits;

    for(auto sites : websites)
    {
        websits.push_back(sites);
    }
    
     int i = 0;
    for(auto date : dates)
    {
       
        int cont = 1;

        Vertex<string, int> * fecha = new Vertex<string, int>(date);

        conexionesC->addVertex(fecha);

        while(cont != 0)
        {
            if(date == "10-8-2020")
            {
                if(i == websiteData.size())
                {
                    cont--;
                    conexionesC->addEdge(C, fecha, cont);
                    break;
                }
                if(websiteData[i].getDestination() == "gmail.com")
                {
                    cont++;
                    
                }
               i++;
            }
            else
            {
                cont --;
                if(cont <= 0)
                {
                    break;
                }else { 
                    conexionesC->addEdge(C, fecha, cont); 
                    }
                
                
            }
        }   
    }
    cout << "gmail.com" << endl;
    return conexionesC;
}

int main()
{   
    /*Vector principal de datos*/
    vector<Register> registros = read_csv("equipo14.csv");

    cout << "-------Vertice de más conexiones de A-----------" << endl;
    
    /*Vector de conexiones de A por día*/
    vector<Register> originIPdata = conectionsTointernal(registros); 

    cout << "-------Vertice con más conexiones hacia A-------" << endl;
    /*Vector de conexiones hacia A por dia*/
    vector<Register> interalIPdata = internalIP(registros);
    /*Grafo de conexiones de IP interna*/
    Graph<string, int> * redInter = grafoRedInter(interalIPdata);
    redInter->MoreConections();

    cout << "-------Conexiones por dia de B-------" << endl;

    /*Vector de datos de sitios web*/
    vector<Register> websitesData = websites(registros);
    Graph<string, int> * weirdSites =  conectiosToB(websitesData);
    weirdSites->MoreConections();


    cout << "--------Más conexiones a C por dia-------" << endl;
    Graph<string, int> * moreConections = conectionsToC(websitesData);
    moreConections->MoreConections();

    cout << "-------------------Preguntas-------------------" << endl;
    
}

