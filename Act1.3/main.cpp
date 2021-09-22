#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iterator>

#include "person.cpp"

using namespace std;

auto readCSV(string filename)
{       
        //Create a Persona vector
    vector<Persona> lines;

        //Read the csv file
    ifstream file(filename);

    if(!file.is_open()) throw runtime_error("Error al leer el archivo");

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

        Persona pers = Persona(date, hour, oIP, oPort, oName, dIP, dPort, dName);
        lines.push_back(pers);
    }

    file.close();

    return lines;
}

int main()
{   
    vector <Persona> personas = readCSV("equipo14.csv");

    //Imprimir el vector

        //copy(personas.begin(), personas.end(), ostream_iterator<Persona>(cout));

        //cout << personas.size();


    return 0;
}