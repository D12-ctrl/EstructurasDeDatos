#ifndef person_hpp
#define person_hpp

#include <iostream>


using namespace std;

class Persona
{
    private:
        string date;
        string hour;
        string originIP;
        string originPort;
        string originName;
        string destinationPort;
        string destinationIP;

    public:
        //~Persona(){}
        Persona(string _date, string _hour, string _originIP, string _originPort, string _originName, string _destinatioPort, 
        string _destinationIP): date(_date), hour(_hour), originIP(_originIP), originPort(_originPort), originName(_originName), 
        destinationPort(_destinatioPort), destinationIP(destinationIP){}

        friend ostream & operator <<(ostream & os, const Persona & persona);
};

#endif