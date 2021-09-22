#ifndef person_hpp
#define person_hpp

#include <iostream>
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
        string destinationPort;
        string destinationIP;
        string destinationName;
/*Fecha, Hora, IP Origen, Puerto Origen, Nombre Origen, IP Destino, Puerto Destino, Nombre Destino*/
    public:
        //~Persona(){}
        Persona(){}
        Persona(string _date, string _hour, string _originIP, string _originPort, string _originName, string _destinatioPort, 
        string _destinationIP, string _dName): date(_date), hour(_hour), originIP(_originIP), originPort(_originPort), originName(_originName), 
        destinationIP(_destinationIP), destinationPort(_destinatioPort), destinationName(_dName){}

        friend ostream & operator <<(ostream & os, const Persona & persona);
        
        auto Date(){return date;}
        auto Hour(){return hour;}
        auto OriginIP(){return originIP;}
        auto OriginPort(){return originPort;}
        auto OriginName(){return originName;}
        auto DestinationPort(){return destinationIP;}
        auto DestinationIP(){return destinationIP;}


        bool comparaDia(Persona); //¿Cuántos récords hay del segundo día registrado? ¿Qué día es este?
        bool comparaNombre(Persona); //¿Alguna de las computadoras pertenece a Jeffrey, Betty, Katherine, Scott, Benjamin, Samuel o Raymond? 
        bool comparaComputador(Persona); // ¿Alguna computadora se llama server.reto.com? 
        bool comparaPuerto(Persona); //Considerando solamente los puertos destino ¿Qué puertos abajo del 1000 se están usando? 

    };

#endif