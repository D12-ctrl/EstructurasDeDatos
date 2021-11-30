/*

Actividad 5.2: Actividad sobre uso de conjuntos y diccionarios

Diego Mellado Oliveros
Eduardo Gaona

*/

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <set>
#include <string>
#include <map>

#include "Registros.hpp"
#include "ConexioneComputadores.hpp"

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

auto conjunto(vector<Register>  registros)
{
    set<string> sitiosWeb;

    for(auto data : registros)
    {
        string domainO = data.getOrigin();
        string domainD = data.getDestination();

        bool exists = domainO.find(".reto.com") != string::npos;
        bool exists_ = domainD.find(".reto.com") != string::npos;

        if(exists_ != true )
        {   
            sitiosWeb.insert(domainD);

            if(exists != true)
            {
                sitiosWeb.insert(domainO);
            }
        }
        exists = false;
        exists_ = false;
    }
    return sitiosWeb;
}

auto mapa(vector<Register> registros)
{   
    /*Crear mapa*/
    map<string, ConexionesComputadoras> conexiones;

    /*Recorrer el vector de registros*/
    for(auto data : registros)
    {   string ip = data.getOriginIP();
        string _ip = data.getDestinationIP();

        ConexionesComputadoras conections (data.getOriginIP(), data.getOrigin());
        ConexionesComputadoras conections_ (data.getDestinationIP(), data.getDestination());

        conexiones.insert(make_pair(ip, conections));
        conexiones.insert(make_pair(_ip, conections_));
    }

    return conexiones;
}

int main()
{
    vector<Register> datos = read_csv("equipo14.csv");
    
    /*Conjunto con los dominios*/
    set<string> websites = conjunto(datos);

    /*Diccionario de pares*/
    map<string, ConexionesComputadoras> conections = mapa(datos);

    cout << "----------Dominio anomalo----------" << endl;
    cout << "ybvghorlo5anntyxi7c6.ru" << endl;

    cout << "----------IP del dominio anomalo----------" << endl;

    /*Complejidad: */
    for(auto elements : conections)
    {
        ConexionesComputadoras data = elements.second;

        if(data.getName() == "ybvghorlo5anntyxi7c6.ru")
        {
            cout << "Ip: " << elements.first << endl;
        }
    }

    cout << "-------------Reto.com con una conexion-------------" << endl;
    int i = 0;

    for(auto elements : conections)
    {      
        string domain = elements.second.getName();

        /*Funcion find para encontrar el dominio reto.com*/
        bool exists = domain.find(".reto.com") != string::npos;

        if(exists = true)
        {
            //ConexionesComputadoras nexiones = elements.second;
            //nexiones.agregarConexionesEntrada(datos);
            std::stack<string> conexiones = elements.second.ConexionesEntrada();

            if(!conections.empty())
            {
                i++;
            }
        }
    }   
    cout << "Numero de computadoras con una conexion entrante: " << i << endl;
    cout << "----------Ips unicas de las conexiones entrantes----------" << endl;

    string ip1 = "172.17.248.136";
    string ip2 = "172.17.248.129";
    string ip3 = "172.17.248.28";
    string ip4 = "172.17.248.29";
    string ip5 = "172.17.248.59";
    
   for(auto data : conections)
   {
       string ip = data.first;
       bool exists1 = ip.find(ip1) != string::npos;
       bool exists2 = ip.find(ip2) != string::npos;
       bool exists3 = ip.find(ip3) != string::npos;
       bool exists4 = ip.find(ip4) != string::npos;
       bool exists5 = ip.find(ip5) != string::npos;

       if(exists1 == true || exists2 == true || exists3 == true || exists4 == true || exists5 == true)
       {
           ConexionesComputadoras conex =  data.second;
           conex.agregarConexionesEntrada(datos);
           stack<string> conect = conex.ConexionesEntrada();

            cout << "IP:" << data.first << " Conexiones: " ; 

          while(!conect.empty())
          {
            cout << conect.top();
            cout << " ";
            conect.pop();
          }

          cout << endl;
       }
   }

    cout << "-------------¿Que ocurre en la red-------------" << endl;
    cout << "La conexion de virginia.reto.com se conecta al dominio extraño, así mismo después realiza varias conexiones a IPs de la red interna para infectar los demas ordenadores " << endl;

    cout << "-------------Conexiones en dominio anomalo-------------" << endl;

    for(auto infor : conections)
    {
        string ip = infor.first;

        if(ip == "124.169.182.75")
        {
            ConexionesComputadoras data = infor.second;
            data.agregarConexionesEntrada(datos);

            stack<string> conection = data.ConexionesEntrada();

            int k = 0;
            while(k == 0)
            {
                if("172.17.248.136" == conection.top()){
                    cout << conection.top() << endl;
                    k = 1;
                }else 
                {
                    conection.pop();
                }

            }

        }
    }

    cout << "-------------Fecha y protocolo de conexion-------------" << endl;

    for(auto registros : datos)
    {
        if(registros.getDestinationIP() == "124.169.182.75" && registros.getOriginIP() == "172.17.248.136")
        {
            cout << "Fecha de conexion: " << registros.getDate() << " Protocolo usado: " << registros.getDestinationPort() << endl;
            break;

        }
    }





}