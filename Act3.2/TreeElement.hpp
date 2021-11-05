/*

Elemento del arbol
Act 3.1

*/

#include <iostream>

template <class T>
class elementTree
{
    private:
        T info;
        //Apuntador al objeto de la izquierda
        elementTree<T> * left = nullptr;
        //Apuntador al objeto de la derecha
        elementTree<T> * right = nullptr;
        //Apuntador al padre
        elementTree<T> * parent = nullptr; 
        //Nivel del nodo
        int level = 0;

    public:
        /*Constructores*/
        elementTree(){};
        elementTree(const T & _info): info(_info){}
        elementTree(const elementTree<T>&);

        /*Desctructor*/
        virtual ~elementTree();

        /*Setters y getters*/  
        int getLevel()const{return level;}
        void setLevel(int value){level = value;}

        T getInfo() const {return info;}
        void setInfo(T & value){return info = value;}

        void setLeft(elementTree<T> * value){left = value;}
        elementTree<T> * getLeft(){return left;}

        void setRight(elementTree * value){right = value;}
        elementTree<T> * getRight(){return right;}

        void setParent(elementTree * value){parent = value;}
        elementTree<T> * getParent(){return  parent;}

        template <typename Tn>
        friend std::ostream & operator << (std::ostream & os, const elementTree<Tn> & node);

};

template <class T>
elementTree<T>::~elementTree()
{
    info.~T();
    left = nullptr;
    right = nullptr;
}

template <class T>
std::ostream & operator << (std::ostream & os, const elementTree<T> & node)
{
    os << node.info;
    
    return os;
}
