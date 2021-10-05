#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>
#include <string>
#include <iterator>

//#include "person.cpp"
#include "interface.cpp"
#include "Ordenamiento.hpp"

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
            int dPort;
            string dIP;
            string dName;
/*Fecha, Hora, IP Origen, Puerto Origen, Nombre Origen, IP Destino, Puerto Destino, Nombre Destino*/
        getline(ss, date, ',');
        getline(ss, hour, ',');
        getline(ss, oIP, ',');
        getline(ss, oPort, ',');
        getline(ss, oName, ',');
        getline(ss, dIP, ',');
        ss >> dPort;
        getline(ss, dName);

        
        Persona pers = Persona(date,hour,oIP,oPort, oName, dIP, dPort, dName);
        lines.push_back(pers);
    }

    file.close();

    return lines;
}

void mostrarResultados(vector<Persona> & personas, string msfg)
{
    if(personas.size() == 0)
    {
        cout << "No hay registros " << endl;
    }
    else
    {
        cout << msfg << endl;
        cout << personas.size() << endl;

    }
}
void menu(Interface & interfac)
{
    int optn;
    vector <Persona> personas;

    do
    { 
        cout << "------MENÚ------"  << endl;
        cout << "1.Añadir los datos" << endl;
        cout << "2.¿Cuántos registros tiene tu archivo? " <<endl;
        cout << "3.¿Cuántos récords hay del segundo día registrado? ¿Qué día es este?" << endl;
        cout << "4.¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿A quiénes?" << endl;
        cout << "5.¿Cuál es la dirección de la red interna de la compañía? " << endl;
        cout << "6.¿Alguna computadora se llama server.reto.com? " << endl;
        cout << "7.¿Qué servicio de correo electrónico utilizan?" << endl;
        cout << "8.Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando?" << endl;
        cout << "9.Quit" << endl;

        cout << "Ingresa la opción" << endl;
        cin >> optn;

        switch (optn)
        {
        case 1:
            personas = readCSV("equipo14.csv");
            break;
        
        case 2:
            cout << "El archivo tiene " << (personas.size()) << " registros. " << endl;
            break;
        
        case 3:
            personas = interfac.recordsxDia("12/08/2020");
            mostrarResultados(personas, "Registros encontrados en la fecha de 12//2020");
            break;

        case 4:
            
            personas = interfac.recordsxNombre("jeffrey.reto.com");
            mostrarResultados(personas, "Jeffrey");

            personas = interfac.recordsxNombre("katherine.reto.com");
            mostrarResultados(personas, "Katherine");

            personas = interfac.recordsxNombre("scott.reto.com");
            mostrarResultados(personas, "Scott");

            personas = interfac.recordsxNombre("benjamin.reto.com");
            mostrarResultados(personas, "Benjamin");

            personas = interfac.recordsxNombre("samuel.reto.com");
            mostrarResultados(personas, "Samuel");

            personas = interfac.recordsxNombre("raymond.reto.com");
            mostrarResultados(personas, "Raymond");

        case 5:
        
            cout << "La red interna es " << interfac.IP();

        case 6:
            personas = interfac.recordsxNombre("server.reto.com");
            mostrarResultados(personas, "Computadores server.reto.com");
        
        case 7:
            personas = interfac.recordsxCorreo("gmail.com");
            mostrarResultados(personas, "Gmail: ");

            personas = interfac.recordsxCorreo("hotmail.com");
            mostrarResultados(personas, "hotmail");

            personas = interfac.recordsxCorreo("outlook.com");
            mostrarResultados(personas, "yahoo.mail.com");
        
        case 8:

       // interfac.ordenar(Ordenamiento<Persona>::burbuja, Persona::comparaPuerto);

        default:
            cout << "Opción inválida" << endl;

            break;
        }
    
    }while(optn != 9);

   
    

}

int main()
{
    Interface intrf;

    menu(intrf);

    return 0;
}


