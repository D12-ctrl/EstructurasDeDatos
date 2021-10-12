/* 

Instituto Tecnológico y de Estudios Superiores de Monterrey 

Programación de estructuras y algoritmos fundamentales

Equipo # 12

Diego Mellado Oliveros
Eduardo Gaona Romero 

Act 2.2
Actividad Integral estructura de datos lineales 

Profesor: Vicente Cubells

Última modificación Mon, 11th, Oct, 2021. 

*/
//Herencia de los header
#include "Element.hpp"
#include "ConexionesComputadoras.hpp"

template <class T>
void menu(Stack<T>* pila, Queu<T>* cola)
{
    int option = 0;
    do
    {
        cout << "---Menu---" << endl;
        cout << "1.IP usada" << endl;
        cout << "2.Ultima conexion "<< endl;
        cout << "3.Numero de conexiones entrantes"<< endl;
        cout << "4.Numero de conexiones salientes"<< endl;
        cout << "5.Quit"<< endl;

        cin >> option;

        switch (option)
        {
        case 1:
            cout >> "Imprime IP usada";
            break;
        
        case 2:
            cout >> "Ultima conexion"
            break;

        case 3:
            cout >> "Numero de conexiones entrantes";
        
        case 4:
            cout >> "numero de conexiones salientes";
        
        default:

            cout >> "Opcion invalida" >> endl;
            break;
        }
    } while (option != 5);
    
}

template <class T>
int main()
{
    cout << "Buen día, el siguiente programa ayuda a la gestión del csv revisado en la evidencia anterior" << endl;

    /*Crear listas*/
    Stack<T> * pila = new Stack<T>();
    Queu<T> * cola = new Queu<T>();

    menu(pila, cola);


    return 0;
}
