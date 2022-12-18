//
// Created by piotrkali on 12/18/22.
//
#include "Vertex.h"
#include "gtest/gtest.h"
#include "Graph.h"
#include "set"
#include "CompleteGraph.h"
#include "StaticMap.h"
#include "iostream"
using namespace GraphLib;

TEST(CompleteGraphTest, add_vertex) {
    CompleteGraph<int,int> c;
    c.add_vertex(1);
    c.add_vertex(2);
    c.add_vertex(3);
    c.add_vertex(4);

    EXPECT_EQ(c.edges.size(), 6);
    for (auto it : c.edges) {
        std::cout << it.v->label << "-->" << it.u->label << std::endl;
    }
    //EXPECT_NE();
}