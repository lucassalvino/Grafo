#ifndef GRAPHUTILS_H
#define GRAPHUTILS_H
#include "customalgorithm.h"

namespace BaseGraph{
class GraphUtils : CustomAlgorithm {
public:
    GraphUtils(){

    }
    std::list<Vertex *> dijkstra(int origin, int destiny, Graph *graph);
    virtual ~GraphUtils();
private:
    void extractMin(std::priority_queue<std::pair<Vertex *, Edge *> *> *prio_queue, int vertex, BaseGraph::Graph *grafo);
};
}
#endif // GRAPHUTILS_H
