#include "interface.hpp"

Interface::~Interface()
{
    logs.clear();
}
string Interface::IP()
{   
    Persona a;
    return a.OriginIP();
}

int Interface::size()
{
    return logs.size();
}

std::vector<Persona> Interface::compara(Persona buscar, bool(comparador)(Persona, Persona))
{
    int i = 0;
    
    vector<Persona> find;
    
    long int size = logs.size();
    
    while (i < size) {
        if ( comparador(logs[i], buscar) ) {
            find.push_back(logs[i]);
        }
        ++i;
    }
    
    return find;
}

vector<Persona> Interface::recordsxDia(string days)
{   days = "12/08/2020";
    Persona search;
    search.Day() = days;

    return compara(search, Persona::comparaDia);
}
vector<Persona> Interface::recordsxNombre(string name)
{   
    Persona search;
    search.OriginName() = name;

    return compara(search, Persona::comparaNombre);
}
vector<Persona> Interface::recordsxPuerto(int port)
{
    Persona search;
    search.DestinationPort() = port;


    return compara(search, Persona::comparaPuerto);
}
vector<Persona> Interface::recordsxCorreo(string mail)
{
    Persona search;

    search.DestinationName() = mail;

    return compara(search, Persona::comparaMail);
}

/*void Interface::ordenar(
                         std::vector<Persona>(* algoritmo)(std::vector<Libro>, bool(*)(Libro,Libro)),
                         bool(* compara)(Libro,Libro)=
{
    logs = algoritmo(logs, compara)
}*/