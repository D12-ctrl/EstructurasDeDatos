#ifndef interface_hpp
#define interface_hpp

#include <iostream>
#include <vector>
#include "person.cpp"

using namespace std;

class Interface
{
    private:
        vector<Persona> logs;

        vector<Persona> compara(Persona, bool(*)(Persona, Persona));
    
    public:
        Interface(){}
        ~Interface();
        vector<Persona> recordsxDia(string);
        vector<Persona> recordsxNombre(string);
        vector<Persona> recordsxCorreo(string);
        vector<Persona> recordsxPuerto(int);
        string IP();
        int size();
        void order(vector<Persona>(*)(vector<Persona>, bool(*)(Persona, Persona)), bool(*)(Persona, Persona));


};
#endif