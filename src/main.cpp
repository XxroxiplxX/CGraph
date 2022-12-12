#include <iostream>
#include "Graph.h"
#include "Vertex.h"
#include "Edge.h"
using namespace GraphLib;
int main() {
    auto G = Graph<int>();
    for (int i = 0; i < 6; i++) {
        G.add_vertex(i);
    }
    for (int i = 0; i < 5; i++){
        G.add_edge(i,i+1,0);
    }
    G.add_edge(0,5,0);
    G.save_to_csv("/tmp/graphs");
    return 0;
}
