#ifndef person_hpp
#define person_hpp

#include <iostream>
#include <cstdlib>

/*¿Cuántos registros tiene tu archivo? 
 
¿Cuál es la dirección de la red interna de la compañía? 

¿Qué servicio de correo electrónico utilizan (algunas ideas: Gmail, Hotmail, Outlook, Protonmail)? 
 */

using namespace std;

class Persona
{
    private:
        string date;
        string hour;
        string originIP;
        string originPort;
        string originName;
        int destinationPort;
        string destinationIP;
        string destinationName;
/*Fecha, Hora, IP Origen, Puerto Origen, Nombre Origen, IP Destino, Puerto Destino, Nombre Destino*/
    public:
        //~Persona(){}
        Persona(){}
        Persona(string _date, string _hour, string _originIP, string _originPort, string _originName, string _destinationIP, int _destinationPort, string _dName): date(_date), hour(_hour), originIP(_originIP), originPort(_originPort), originName(_originName), destinationIP(_destinationIP), destinationPort(_destinationPort), destinationName(_dName){}

        friend ostream & operator <<(ostream & os, const Persona & persona);
        
        auto Day() ->string & {return date;}
        auto Day() const -> const string& {return date;}
        //auto OriginIP(){return originIP;}
        string OriginName(){return originName;}

        auto DestinationPort()-> int& {return destinationPort;}
        auto DestinationPort() const-> const int &{return destinationPort;}

       string DestinationName(){return destinationName;}

        auto OriginIP() ->string& {return originIP;}
        auto OriginIP() const-> const string&{return originIP;}


        static bool comparaDia(Persona, Persona); //¿Cuántos récords hay del segundo día registrado? ¿Qué día es este?
        static bool comparaNombre(Persona, Persona); //¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? ¿Alguna computadora se llama server.reto.com? 
        static bool comparaPuerto(Persona, Persona); //Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? 
        static bool comparaMail(Persona, Persona); // ¿Qué servicio de correo electrónico utilizan?
    };

#endif