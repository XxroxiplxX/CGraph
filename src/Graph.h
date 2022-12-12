//
// Created by piotrkali on 11/26/22.
//

#ifndef CGRAPH_GRAPH_H
#define CGRAPH_GRAPH_H


#include <vector>
#include "Vertex.h"
#include "Edge.h"
#include "fstream"
namespace GraphLib {
    template <class T>
    class Graph {
        std::vector<Vertex<T>> vertices;
        std::vector<Edge<T>> edges;

    public:
        Vertex<T>* get_vertex(T label);
        Graph() {}
        int distance(Vertex<T> u, Vertex<T> v);
        void add_vertex(Vertex<T> v);
        void add_vertex(T t);
        void add_edge(Vertex<T>* u, Vertex<T>* v, T label);
        void add_edge(T ut, T vt, T label);
        std::vector<Vertex<T>*> get_neighbours(Vertex<T> u);
        int min_degree();
        int max_degree();
        std::vector<Vertex<T>>get_vertices();
        std::vector<Edge<T>>get_edges();
        int eccentricity(Vertex<T>* u);
        int diameter();
        int radius();
        void save_to_csv(std::string path);
    };

    template<class T>
    int Graph<T>::min_degree() {
        int min = vertices[0].degree();
        for (auto it : vertices) {
            if (it.degree() < min) {
                min = it.degree();
            }
        }
        return min;
    }

    template<class T>
    std::vector<Vertex<T>> Graph<T>::get_vertices() {
        return vertices;
    }

    template<class T>
    void Graph<T>::add_vertex(Vertex<T> v) {
        vertices.push_back(v);
    }

    template<class T>
    void Graph<T>::add_edge(Vertex<T>* u, Vertex<T>* v, T label) {
        edges.push_back(Edge<T>(u,v,label));
        for (Vertex<T> n : &(u->get_neighbours())) {
            n.get_neighbours().push_back(u);
        }
        for (Vertex<T> n : &(v->get_neighbours())) {
            n.get_neighbours().push_back(v);
        }
    }

    template<class T>
    std::vector<Edge<T>> Graph<T>::get_edges() {
        return edges;
    }

    template<class T>
    void Graph<T>::add_vertex(T t) {
        vertices.push_back(Vertex<T>(t));
    }

    template<class T>
    std::vector<Vertex<T> *> Graph<T>::get_neighbours(Vertex<T> u) {
        return u.get_neighbours();
    }

    template<class T>
    int Graph<T>::max_degree() {
        int max = vertices[0].degree();
        for (auto it : vertices) {
            if (it.degree() > max) {
                max = it.degree();
            }
        }
        return max;
    }

    template<class T>int Graph<T>::distance(Vertex<T> u, Vertex<T> v) {
        return u.dist(v, 0);
    }

    template<class T>
    int Graph<T>::eccentricity(Vertex<T> *u) {
        int max_dist = 0;
        int tmp;
        for (auto v : vertices) {
            tmp = u->dist(v, 0);
            if (tmp > max_dist) {
                max_dist = tmp;
            }
        }
        return max_dist;
    }

    template<class T>
    int Graph<T>::diameter() {
        int max = 0;
        int tmp;
        for (auto vertex : vertices) {
            tmp = eccentricity(vertex);
            if (tmp > max) {
                max = tmp;
            }
        }
        return max;
    }

    template<class T>
    int Graph<T>::radius() {
        int min = vertices[0];
        int tmp;
        for (auto vertex : vertices) {
            tmp = eccentricity(vertex);
            if (tmp < min) {
                min = tmp;
            }
        }
        return min;
    }

    template<class T>
    void Graph<T>::add_edge(T ut, T vt, T label) {
        auto u = get_vertex(ut);
        auto v = get_vertex(vt);
        if (!(u and v)) {
            return;
        }
        edges.push_back(Edge<T>(u,v, label));
        for (auto n : (u->get_neighbours())) {
            n->get_neighbours().push_back(u);
        }
        for (auto n : (v->get_neighbours())) {
            n->get_neighbours().push_back(v);
        }
    }

    template<class T>
    void Graph<T>::save_to_csv(std::string path) {
        std::ofstream outdata_v;
        std::ofstream outdata_e;
        outdata_v.open(path + "/graph_v.csv");
        outdata_e.open(path + "/graph_e.csv");
        outdata_v << "v" << ";" << std::endl;
        outdata_e << "e1" << ";" << "e2" << std::endl;
        for (auto vertex : vertices) {
            outdata_v << vertex.label << ";" << std::endl;
        }
        outdata_v.close();
        for (auto edge : edges) {
            outdata_e << edge.u->label << ";" << edge.v->label << std::endl;
        }
        outdata_e.close();
    }

    template<class T>
    Vertex<T>* Graph<T>::get_vertex(T l) {
        Vertex<T>* ptr = nullptr;
        for (int i = 0; i < vertices.size(); i++) {
            if (vertices[i].label == l) {
                ptr = &vertices[i];
                return ptr;
            }
        }
        return nullptr;
    }

}


#endif //CGRAPH_GRAPH_H
