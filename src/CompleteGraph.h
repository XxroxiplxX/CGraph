//
// Created by piotrkali on 12/16/22.
//

#ifndef CGRAPH_COMPLETEGRAPH_H
#define CGRAPH_COMPLETEGRAPH_H
#include "Graph.h"
namespace GraphLib {
    template<class T, class L>
    class CompleteGraph : public Graph<T,L>{

    public:
        CompleteGraph(){};
        CompleteGraph(int size);
    };
}
#endif //CGRAPH_COMPLETEGRAPH_H
