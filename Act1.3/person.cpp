#include "person.hpp"


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