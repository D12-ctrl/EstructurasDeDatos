//
//  Graph.hpp
//  Graph
//
//  Created by Vicente Cubells on 10/11/20.
//

#ifndef Graph_hpp
#define Graph_hpp

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <iterator>
#include "Vertex.hpp"

template <class V, class E>
class Graph 
{
protected:

    std::vector < Vertex<V, E> * > nodes;
    
public:
    Graph() {}
    ~Graph();
    
    void addVertex(V & );
    void addVertex(Vertex<V,E> * );
    void addEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    void removeEdge(Vertex<V,E> *, Vertex<V,E> *, const E & );
    void MoreConections();

    template <class Vn, class En>
    friend std::ostream & operator <<(std::ostream &, const Graph<Vn,En> &);
};

template <class V, class E>
Graph<V,E>::~Graph()
{
    for (auto v: nodes) {
        delete v;
    }
    
    nodes.clear();
}

template <class V, class E>
void Graph<V,E>::addVertex(V & value )
{
    auto vertex = new Vertex<V, E>(value);
    
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addVertex(Vertex<V,E> * vertex )
{
    nodes.push_back(vertex);
}

template <class V, class E>
void Graph<V,E>::addEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value)
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    /* Crear un edge y adicionarlo al vertex */
    Edge<V, E> * edge = new Edge<V,E>(value, target);
    
    (*node)->addEdge(edge);
}

template <class V, class E>
void Graph<V,E>::removeEdge(Vertex<V,E> * source, Vertex<V,E> * target, const E & value )
{
    /* Buscar vertex origen */
    auto node = find(nodes.begin(), nodes.end(), source);
    
    Vertex<V,E> * vertex = (*node);
    
    auto * edges = vertex->getEdges();
    
    Edge<V,E> * to_remove = nullptr;
    
    for (auto e : *edges) {
        if (e->getInfo() == value && e->getTarget() == target) {
            to_remove = e;
            break;
        }
    }
    
    if (to_remove) {
        vertex->removeEdge(to_remove);
    }
    
}

template <class V, class E>
std::ostream & operator <<(std::ostream & os, const Graph<V,E> & graph)
{
    os << "--- Graph ---" << std::endl;
    
    for (auto v :  graph.nodes) {
        os << *v;
    }
    
    return os;
}
template <class V, class E>
void Graph<V,E>::MoreConections()
{   
    int i = 0;

    Vertex<V,E> * source = nodes[0];
    auto node = find(nodes.begin(), nodes.end(), source);

    Vertex<V,E> * vertex = (*node);

    auto * edges = vertex->getEdges();

    std::vector<int> conexiones;

    for (auto e : *edges)
    {   
        auto infor = e->getInfo();
        conexiones.push_back(infor);
  
    } 
    
    int cont = 0;
    std::sort(conexiones.begin(), conexiones.end(), std::greater<int>());
    
    for(auto ed : *edges)
    {
        int i = 0; 
        while(i == 0)
        {
            if(ed->getInfo() == conexiones[0])
            {
                std::cout << nodes[cont]->getInfo() << " " << conexiones[0] << std::endl;
                break;
            }
            else
            {
                i = 1;
                cont++;
            }
        }
    }


}

#endif /* Graph_hpp */
