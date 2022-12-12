//
// Created by piotrkali on 11/26/22.
//

#ifndef CGRAPH_EDGE_H
#define CGRAPH_EDGE_H

#include "Vertex.h"

namespace GraphLib {
    template <class T>
    class Vertex;


    template <class T>
    class Edge {
    public:
        Edge(){}
        Edge(Vertex<T>* u, Vertex<T>* v, T label);

        Vertex<T>* u;
        Vertex<T>* v;
    protected:
        T label;
    };

    template<class T>
    Edge<T>::Edge(Vertex<T> *u, Vertex<T> *v, T label) : u(u), v(v), label(label){

    }
}


#endif //CGRAPH_EDGE_H
