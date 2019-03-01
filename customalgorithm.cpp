#include "customalgorithm.h"

BaseGraph::CustomAlgorithm::CustomAlgorithm(Graph *pointerGraph)
{
    graph = nullptr;
    if(pointerGraph == nullptr)
        throw std::string("He necessario informar um grafo valido");
    graph = pointerGraph;
}

BaseGraph::CustomAlgorithm::CustomAlgorithm()
{
    graph = nullptr;
}

void BaseGraph::CustomAlgorithm::execute()
{
    throw std::string("ainda nao foi implementado");
}

void BaseGraph::CustomAlgorithm::setInstanceGraph(Graph *pointerGraph)
{
    if(pointerGraph == nullptr)
        throw std::string("He necessario informar um grafo valido");
    else
        graph = pointerGraph;
}

void BaseGraph::CustomAlgorithm::checkInstanceGraph()
{
    if(graph == nullptr)
        throw std::string("He necessario informar um grafo valido");
    else
        return;
}

double BaseGraph::CustomAlgorithm::getDistance(int a, int b)
{
    checkInstanceGraph();
    return graph->getEdge(a,b)->getDistance();
}
