#include "person.hpp"
#include <sstream>
#include <iostream>


ostream & operator<<(ostream & os, const Persona & persona)
{
    os << persona.date << " - ";
    os << persona.hour << " - ";
    os << persona.originIP << " - ";
    os << persona.originPort << " - ";
    os << persona.originName << " - ";
    os << persona.destinationPort << " - ";
    os << persona.destinationIP << " - ";

    return os;
}

bool Persona::comparaDia(Persona a, Persona b)
{
    return a.Day() == b.Day(); // Comparar los días
}
bool Persona::comparaNombre(Persona a, Persona b)
{
    return a.OriginName() == b.OriginName(); //Comparar los nombres
}
bool Persona::comparaPuerto(Persona a, Persona b)
{
    return a.DestinationPort() > b.DestinationPort(); //Comparar los puertos de destino
}
bool Persona::comparaMail(Persona a, Persona b)
{
    return a.DestinationName() ==  b.DestinationName(); // COmparar los nombres de destino
}