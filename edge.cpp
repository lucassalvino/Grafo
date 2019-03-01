#include "edge.h"

BaseGraph::Edge::Edge(int id)
{
    origin = nullptr;
    destiny = nullptr;
    distance = 0;
    this->ID = id;
}

void BaseGraph::Edge::setOrigin(Vertex *value)
{
    if (value == nullptr) throw std::string("O ponteiro para o vertice de origem nao pode ser nulo");
    origin = value;
}

void BaseGraph::Edge::setDestiny(Vertex *value)
{
    if (value == nullptr) throw std::string("O ponteiro para o vertice de destino nao pode ser nulo");
    if (origin == nullptr) throw std::string("O Ponteiro para a origem ainda nao foi setado, set a origem primeiro");
    destiny = value;
    origin->addVertexAdjacent(destiny);
}

void BaseGraph::Edge::setDistance(double value)
{
    distance = value;
}

BaseGraph::Vertex *BaseGraph::Edge::getOrigin()
{
    return origin;
}

BaseGraph::Vertex *BaseGraph::Edge::getDestiny()
{
    return destiny;
}

double BaseGraph::Edge::getDistance()
{
    return distance;
}

std::pair<int, int> BaseGraph::Edge::getOriginDestiny()
{
    if(origin && destiny)
        return std::pair<int ,int>(origin->getId(), destiny->getId());
    else
        throw std::string("Ainda nao foi realizado o set da origem ou do destino");
}

int BaseGraph::Edge::getId()
{
    return this->ID;
}
