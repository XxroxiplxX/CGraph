//
// Created by piotrkali on 11/27/22.
//
#include "Vertex.h"
#include "gtest/gtest.h"
#include "Graph.h"

using namespace GraphLib;

namespace GraphLib {
    TEST(VERTEX_TEST, Inc_TEST) {
        auto G = Graph<int>();
        for (int i = 0; i < 6; i++) {
            G.add_vertex(i);
        }
        //auto p = G.get_node(3);
        //EXPECT_TRUE(G.get_node(3) != nullptr);
       //auto v = new Vertex<int>();
       // auto w = new Vertex<int>();
        //v->neighbours = {new Vertex<int>(), new Vertex<int>(), w};
        //EXPECT_TRUE(v->isIncidental(w));

    }
}
