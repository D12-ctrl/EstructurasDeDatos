/*

Elemento del arbol
Act 3.2

*/

#include <iostream>


class elementTree
{
    protected:

        std::string date;
        std::string hour;
        std::string origin;
        std::string originIP;
        int originPort;
        
        std::string destination;
        std::string destinationIP;
        int destinationPort;
    private:
        
        //Apuntador al objeto de la izquierda
        elementTree * left = nullptr;
        //Apuntador al objeto de la derecha
        elementTree * right = nullptr;
        //Apuntador al padre
        elementTree * parent = nullptr; 
        //Nivel del nodo
        int level = 0;

    public:
        /*Constructores*/
        elementTree(std::string _fecha, std::string _hora,
            std::string _origen, std::string _ipo, int _pto,
            std::string _destino, std::string _ipd, int _ptod):
            date(_fecha), hour(_hora), origin(_origen), originIP(_ipo), originPort(_pto),
            destination(_destino), destinationIP(_ipd), destinationPort(_ptod){};
        elementTree(const elementTree&);

        /*Desctructor*/
        virtual ~elementTree();

        /*Setters y getters*/  
        int getLevel()const{return level;}
        void setLevel(int value){level = value;}
        
        std::string getFecha() const{return date;}
        std::string getHora() const {return hour; }
        std::string getOrigen() const {return origin; }
        std::string getIPOrigen() const {return originIP;}
        int getPuertoOrigen() const {return originPort;}
        std::string getDestino() const {return destination;}
        std::string getIPDestino() const {return destinationIP;}
        int getPuertoDestino() const {return destinationPort;}
        

        void setLeft(elementTree * value){left = value;}
        elementTree * getLeft(){return left;}

        void setRight(elementTree * value){right = value;}
        elementTree * getRight(){return right;}

        void setParent(elementTree * value){parent = value;}
        elementTree * getParent(){return  parent;}

        //template <typename Tn>
        //friend std::ostream & operator << (std::ostream & os, const elementTree<Tn> & node);

};

/*
elementTree::~elementTree()
{

    left = nullptr;
    right = nullptr;
}


std::ostream & operator << (std::ostream & os, const elementTree & node)
{
    os << node.date << ", ";
    os << node.hour << ", ";
    os << node.originIP << ", ";
    os << node.puerto_origen << ", ";
    os << node.origen << ", ";
    
    os << node.ip_destino << ", ";
    os << node.puerto_destino << ", ";
    os << node.destino;
    os << std::endl;
    
    return os;
}*/
