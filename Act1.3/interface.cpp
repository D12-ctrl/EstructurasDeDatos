#include "interface.hpp"

Interface::~Interface()
{
    logs.clear();
}

unsigned long Interface::size()
{
    return logs.size();
}

std::vector<Persona> Interface::compara(Persona buscar, bool(comparador)(Persona, Persona))
{
    int i = 0;
    
    std::vector<Persona> find;
    
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
{
    Persona search;
    days = "12";

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
    search.destinationName() = mail;

    return compara(search, Persona::comparaMail);

}