#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include <utility>
#include "vertex.h"
#include <vector>
namespace  BaseGraph {
    class Edge
    {
    public:
        Edge(int id = -1);
        void setOrigin(Vertex* value);
        void setDestiny(Vertex* value);
        void setDistance(double value);
        Vertex* getOrigin();
        Vertex* getDestiny();
        double getDistance();
        std::pair<int,int> getOriginDestiny();
        int getId();
    protected:
        Vertex* origin;
        Vertex* destiny;
        double distance;
        int ID;
    };
}
#endif // EDGE_H
