/*

Actividad 3.1

*/

#include <iostream>

#pragma once

class Register
{
    /*Declaracion de variables*/
    std::string date;
    std::string hour;
    std::string origin;
    std::string originIP;
    std::string originPort;

    std::string destination;
    std::string destinationIP;
    std::string destinationPort;
    
    public:

    /*Constructor*/
    Register(std::string _date, std::string _hour, std::string _origin, 
            std::string _originIP, std::string _originPort, std::string _destination,
            std::string _destinationIP, std::string _destinationPort): 
            date(_date), hour(_hour), origin(_origin), originIP(_originIP), 
            originPort(_originPort), destination(_destination), destinationIP(_destinationIP),
            destinationPort(_destinationPort){}

    /*Getters*/

    std::string getDate() const {return date;}
    std::string getHour() const {return hour;}
    std::string getOrigin() const {return origin;}
    std::string getOriginIP () const {return originIP;}
    std::string getOriginPort() const {return originPort;}
    std::string getDestination() const {return destination;}
    std::string getDestinationIP() const {return destinationIP;}
    std::string getDestinationPort() const {return destinationPort;}
};