/*

BST.hpp
Act3.1

*/

#include "binaryTree.hpp"
#include <iostream>


template <class T>
class BST: public BinaryTree<T>
{
    public:
        BST(){};
        virtual ~BST(){}

        elementTree<T> * search(const T &)const;
        bool insert(T &);
        bool insert(elementTree<T> *);  
        /*Desplegara los datos dependiento del algoritmo de busqueda seleccionado*/    
        void visit();
        /*Altura del BST*/
        int height();
        /*Ancestros de un datos*/
        void ancestors(const T&);
        /*Nivel que se encuentra un dato*/
        int levelAm(const T&);

}; 

template <class T>
elementTree<T> * BST<T>::search(const T & value)const
{
    elementTree<T> * temp = this->root;

    while(temp != nullptr)
    {
        if(temp->getInfo() == value)
        {
            return temp;
        }
        else 
        {
            temp = temp->getInfo() > value ? temp->getLeft() : temp->getRight();
        }
    }

    return nullptr;
}

template <class T>
bool BST<T>::insert(T &value)
{
    return this->insert(new elementTree(value));
}

template <class T>
bool BST<T>::insert(elementTree<T> * node)
{
    if(node == nullptr)
        return false;
    
    //Obtener la información del nodo
    T value = node->getInfo();

    //Apuntador temporal
    elementTree<T> * temp = this->root;

    //Apuntador temporal para el nodo padre
    elementTree<T> * parent = nullptr;

    while(temp != nullptr)
    {
        if(temp->getInfo() == value)
        {
            //Eliminar el nodo que ya existe
            delete node;

            return false;
        }else
        {
            parent = temp;
            temp = temp->getInfo() > value ? temp->getLeft() : temp->getRight();
        }
    }

    //establecer nodo padre
    node->setParent(parent);

    //Si el arbol esta vacio, se inserta como raiz

    if(parent == nullptr)
    {
        this->root = node;
    }else
    {
        if(parent->getInfo() > value)
        {
            parent->setLeft(node);
        }else
        {
            parent->setRight(node);
        }
    }

    return true;
}

template <class T>
void BST<T>::visit()
{
    int option = 0;
    do
    {
        std::cout << "1. Preorder" << std::endl;
        std::cout << "2. Inorder" << std::endl;
        std::cout << "3. Postorden" << std::endl;
        std::cout << "4. Level by level" << std::endl;
        std::cout << "5. Quit" << std::endl;
        std::cin >> option;

        switch (option)
        {
        case 1:
            this->preOrden();
            break;

        case 2:
            this->inOrden();
            break;

        case 3:
            this->postOrden();
            break;
        case 4:
            this->level();
            break;

        default:
            std::cout << "Opcion invalida" << std::endl;
            break;
        }
    } while (option != 5);
    
}

template <class T>
int BST<T>::height()
{
    return this->Height();
}

/*Complejidad logaritmica*/
template <class T>
void BST<T>::ancestors(const T& value)
{
    elementTree<T> * exist = this->search(value);

    if(exist != nullptr)
    {
        while(exist->getParent() != nullptr)
        {
            elementTree<T> * antcesor = exist->getParent();
            std::cout << antcesor->getInfo() << std::endl;
            exist = exist->getParent();

        }
    }

}

/*Complejidad constante*/
template <class T>
int BST<T>::levelAm(const T & value)
{
    elementTree<T> * node = this->search(value);

    return node->getLevel();
}
