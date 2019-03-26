#ifndef GRAPH_H
#define GRAPH_H
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <set>
#include <utility>
#include <limits>
#include <queue>
#include <utility>
#include <list>

namespace  BaseGraph {
    class Graph
    {
    public:
        Graph();
        void addEdge(int origin, int destiny, double distance,int ID = -1, bool bidirectional=false, bool updateDistance = false);
        void clear();
        void loadFromFile(std::string source);
        void saveInFile(std::string source);
        Edge *getEdge(int origin, int destiny);
        Edge *getEdge(Vertex origin, Vertex destiny);
        Edge *getEdge(int id);
        Vertex* getVertex(int id, bool add = false);
        Vertex* getVertexIndex(int index);
        unsigned int getNumEdge();
        unsigned int getNumVertex();
        double **getMatrix();
    protected:
        std::vector<Vertex*> vertex;
        std::vector<Edge> edges;
        void addEdge(Vertex *origin, Vertex *destiny, double distance, int ID = -1, bool updateDistance = false);
    private:
        void addVertex(int id);
        void addEdge(Edge value, bool updateDistance = false);
        void verificaIDEdge(int&ID);
        int temp_id_edge;
    };
}
#endif // GRAPH_H
