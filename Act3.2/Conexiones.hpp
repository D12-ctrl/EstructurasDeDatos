/*

Actividad 3.2

*/

#include <iostream>
#include <vector>

class Conexiones
{
    /*Declaracion de variables*/
    std::string _ip;
    std::string _name;
    std::vector<std::string> input;
    std::vector<std::string> output;

    public:

    Conexiones(std::string ip, std::string name)
    {
        this->_ip = ip;
        this->_name = name;
    }

    std::string getIP() const
    {
        return this->_ip;
    }
};