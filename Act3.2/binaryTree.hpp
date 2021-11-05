/*

Arbol binario

Act 3.1

*/

#include <iostream>
#include <queue>
#include "TreeElement.hpp"

template <class T>
class BinaryTree
{
    protected:
        /*Elemento raíz*/
        elementTree<T> * root = nullptr;

        void clear(elementTree<T>*);
        int height = 0;

    public:
        BinaryTree(){};
        virtual ~BinaryTree();
        /*Setter y getter altura*/
        void setHeight(int h){height =  h;}
        int getHeight(){return height;}

        /*Insertar un nodo en el arbol*/
        bool insert(T&, elementTree<T>*);
        bool insert(elementTree<T>*, elementTree<T>*);

        /*Revisa si el arbol esta vacio*/
        bool empty();

        /*Eliminar un nodo del árbol*/
        void clear();

        /*Recorridos del arbol*/
        void preOrden() const;
        void preOrden(elementTree<T>*) const;

        void inOrden() const;
        void inOrden(elementTree<T>*) const;

        void postOrden() const;
        void postOrden(elementTree<T> *) const;

        void level();
        void level(elementTree<T>*);

};

template <class T>
void BinaryTree<T>::clear()
{
    this-> clear(this->root);
    this -> root = nullptr;
}

template <class T>
void BinaryTree<T>::clear(elementTree<T> * node)
{
    if (node != nullptr)
    {
        clear(node->getLeft());
        clear(node->getRight());
        delete node;
    }
    
}

template <class T>
BinaryTree<T>::~BinaryTree()
{
    this->clear();
}

template <class T>
bool BinaryTree<T>::empty()
{
    return this->root == nullptr;
}

template <class T>
bool BinaryTree<T>::insert(T & value, elementTree<T> * parent)
{
    return this->insert(new elementTree<T>(value), parent);
}

template <class T>
bool BinaryTree<T>::insert(elementTree<T> * node, elementTree<T> * parent)
{
    bool inserted = false;

    //Verificar si el arbol esta vacio
    if(this-> root == nullptr)
    {
        //Establecer un nuevo nodo raiz
        this->root = node;
    } else if (parent == nullptr)
    {
        node->setLeft(root);
        root = node;
    }
    else
    {
        if(parent->getLeft() == nullptr)
        {
            parent->setLeft(node);
            inserted = true;
        }
        else if(parent->getRight() == nullptr)
        {
            parent->setRight(node);
            inserted = true;
        }
        else
        {
            inserted = insert(node, parent->getLeft());
            if(!inserted)
            {
                insert(node, parent->getRight());
            }
        }
    }

    return inserted;
}

    /*Recorridos de un arbol*/

//Complejidad logaritmica
template <class T>
void BinaryTree<T>::preOrden()const
    {
        this->preOrden(this->root);
    }

template <class T>
void BinaryTree<T>::preOrden(elementTree<T> * node)const
    {
        if(node != nullptr)
        {
            std::cout << *node << "" << std::endl;

                //Despleazarse a la izquierda
            preOrden(node->getLeft());
                //Desplazar a la derecha
            preOrden(node->getRight());
        }
    }

//Complejidad logaritmica
template <class T>
void BinaryTree<T>::inOrden() const
    {
        this->inOrden(this->root);
    }

template <class T>
void BinaryTree<T>::inOrden(elementTree<T> * node) const
    {
        if(node != nullptr)
        {
            inOrden(node->getLeft());

            std::cout << *node << "" << std::endl;

            inOrden(node->getRight());
        }
    }

//Complejidad logaritmica
template <class T>
void BinaryTree<T>::postOrden() const
    {
        this->postOrden(this->root);
    }

template <class T>
void BinaryTree<T>::postOrden(elementTree<T>* node) const
    {
        if(node != nullptr)
        {
            preOrden(node->getLeft());

            preOrden(node->getRight());

            std::cout << *node << "" << std::endl;
        }
    }

//Complejidad logaritmica
template <class T>
void BinaryTree<T>::level()
{
    if(!empty())
    {
        this->root->setLevel(1);
        this->level(this->root);
    }
}

template <class T>
void BinaryTree<T>::level(elementTree<T>* node)
{
    std::queue<elementTree<T> * > q;

    int currentLevel = 0;
    q.push(node);

    elementTree<T> * temp;

    while(!q.empty())

    {  /*Obtener el primer elemento*/
        temp = q.front();
        q.pop();
 
        //Insertar el izquierdo
        elementTree<T> * left = temp->getLeft();
        if(left != nullptr)
        {
            left->setLevel(temp->getLevel()+1);
            q.push(left);
        }
        //Insertar el hijo derecho
        elementTree<T> * right = temp->getRight();
        if(right != nullptr)
        {   
            right->setLevel(temp->getLevel()+1);
            q.push(right);
        }

        if(height != temp->getLevel())
        {
            //std::cout << *temp;
            std::cout << std:: endl;
            currentLevel++;
        }

        std::cout << *temp << "";

    }

    this->setHeight(currentLevel);

   
}