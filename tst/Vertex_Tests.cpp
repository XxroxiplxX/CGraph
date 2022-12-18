//
// Created by piotrkali on 11/27/22.
//
#include "Vertex.h"
#include "gtest/gtest.h"
#include "Graph.h"
#include "set"
#include "CompleteGraph.h"
#include "StaticMap.h"
using namespace GraphLib;

namespace GraphLib {
    TEST(VERTEX_TEST, Inc_TEST) {
        auto G = Graph<int, int>();
        for (int i = 0; i < 6; i++) {
            G.add_vertex(i);
        }
        /*auto x = G;
        G.add_edge(0,1,0);
        EXPECT_NE(G.get_edges().size(), x.get_edges().size());
        std::vector<Vertex<int>> vec = {Vertex<int>(1),Vertex<int>(2),Vertex<int>(3)};
        auto C = Graph<int>(vec);
        C.add_vertex(5);
        auto e = G.get_edge(0,1);
        std::cout << e << std::endl;
        //auto e = G.minimal_spanning_tree_Prim(2);
        //auto s = std::set<>
        C.save_to_csv("/tmp/graphs");
        */
        G.add_edge(0,1,2);
        G.add_edge(1,2,6);
        G.add_edge(2,3,3);
        G.add_edge(3,4,16);
        G.add_edge(4,5,30);
        G.add_edge(5,0,20);


        G.add_edge(0,2,12);
        G.add_edge(0,5,122);
        G.add_edge(1,3,21);
        G.add_edge(1,4,2);
        //std::cout << G.get_vertex(2)->get_neighbours()->size();
        auto T = G.minimal_spanning_tree_Prim(2);
        T.save_to_csv("/tmp/graphs");
        //auto p = G.get_node(3);
        //EXPECT_TRUE(G.get_node(3) != nullptr);
       //auto v = new Vertex<int>();
       // auto w = new Vertex<int>();
        //v->neighbours = {new Vertex<int>(), new Vertex<int>(), w};
        //EXPECT_TRUE(v->isIncidental(w));

    }
    TEST(VERTEX_TEST, NEIGHBOUR_TEST) {
        auto G = Graph<int, int>();
        for (int i = 0; i < 6; i++) {
            G.add_vertex(i);
        }
        G.add_edge(0,1,2);
        G.add_edge(1,2,6);
        G.add_edge(2,3,3);
        G.add_edge(3,4,16);
        G.add_edge(4,5,0);
        G.add_edge(5,0,20);


        G.add_edge(0,2,12);
        G.add_edge(0,5,122);
        G.add_edge(1,3,21);
        G.add_edge(1,4,2);
        //G.save_to_csv("/tmp/graphs");
        EXPECT_EQ(G.get_vertices()[2].get_neighbours()->size(), 3);
        CompleteGraph<int,int> c;
        c.add_vertex(1);
        c.add_vertex(2);
        c.add_vertex(3);
        c.add_vertex(4);
        c.add_vertex(5);
        c.add_vertex(6);
        EXPECT_EQ(c.edges.size(), 15);
        //c.add_vertex(7);
        c.save_to_csv("/tmp/graphs");

    }

}
