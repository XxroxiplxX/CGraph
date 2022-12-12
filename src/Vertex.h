//
// Created by piotrkali on 11/27/22.
//

#ifndef CGRAPH_VERTEX_H
#define CGRAPH_VERTEX_H
#include "vector"

#include "map"
#include "algorithm"
namespace GraphLib {
    //template <class T>
    //class Edge;


    template <class T>
    class Vertex {
        std::vector<Vertex<T>*> neighbours;
    public:
        Vertex(){}
        Vertex(T l);

        T label;
        std::vector<Vertex<T>*> get_neighbours();

        int eccentricity();
        bool isIncidental(Vertex<T>* v);
        int dist(Vertex<T> v, int acc);
        int degree();
};

    template<class T>
    bool Vertex<T>::isIncidental(Vertex<T>* v) {
        if (std::find(neighbours.begin(), &neighbours.end(), v)) {
            return true;
        }
        return false;
    }

    template<class T>
    int Vertex<T>::degree() {
        return neighbours.size();
    }

    template<class T>
    Vertex<T>::Vertex(T l) : label(l) {

    }

    template<class T>
    std::vector<Vertex<T> *> Vertex<T>::get_neighbours() {
        return neighbours;
    }

    template<class T>
    int Vertex<T>::eccentricity() {
        return 0;
    }

    template<class T>
    int Vertex<T>::dist(Vertex<T>v, int acc) {
        for (auto neighbour : neighbours) {
            if (v.isIncidental(*neighbour)) {
                return 1;
            } else {
                return dist(neighbour, acc+1);
            }
        }
    }


}
#endif //CGRAPH_VERTEX_H
