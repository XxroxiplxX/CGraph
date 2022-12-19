//
// Created by piotrkali on 12/16/22.
//

#ifndef CGRAPH_COMPLETEGRAPH_H
#define CGRAPH_COMPLETEGRAPH_H
#include "Graph.h"
#include "iostream"
namespace GraphLib {

//testaaaa

    template<class T, class L>
    class CompleteGraph : public Graph<T,L>{

        //void add_edge(Vertex<T>* u, Vertex<T>* v, L label);
        //void add_edge(T ut, T vt, L label) override;

    public:
        CompleteGraph(){};
        CompleteGraph(int size);
        void add_vertex(Vertex<T> v);
        void add_vertex(T t);
    };

    template<class T, class L>
    void CompleteGraph<T, L>::add_vertex(Vertex<T> v) {
        for (int i = 0; i < this->vertices.size(); i++) {
            this->add_edge(&v, &(this->vertices[i]));
        }
        this->vertices.push_back(v);
    }
    /*
     * interesting, change v to implicit object
     */
    template<class T, class L>
    void CompleteGraph<T, L>::add_vertex(T t) {
        auto v = new Vertex<T>(t);
        for (int i = 0; i < this->vertices.size(); i++) {
            this->add_edge(v, &(this->vertices[i]));
            std::cout << "added edge between " << v << " and " << &this->vertices[i].label << std::endl;
        }
        this->vertices.push_back(*v);
        
    }

    template<class T, class L>
    CompleteGraph<T, L>::CompleteGraph(int size) {

    }
}
#endif //CGRAPH_COMPLETEGRAPH_H
