#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>

#include "person.hpp"

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

        getline(ss, date, ',');
        getline(ss, hour, ',');
        getline(ss, oIP, ',');
        getline(ss, oPort, ',');
        getline(ss, oName, ',');
        getline(ss, dPort, ',');
        getline(ss, dIP, ',');

        lines.push_back(Persona(date, hour, oIP, oPort, oName, dPort, dIP));
    }

    file.close();

    return lines;
}

int main()
{   
    readCSV("equipo14.csv");

    
}