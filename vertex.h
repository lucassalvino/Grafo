#ifndef VERTEX_H
#define VERTEX_H

#include <iostream>
#include <vector>
namespace  BaseGraph {
class Vertex
{
public:
    Vertex();
    Vertex(int id);
    ~Vertex();
    void setId(int value);
    int getId();
    int numberAdjacents();
    Vertex* getAdjacentAt(int index);
    std::vector<int> getIDVertexAdjacent();
    void addVertexAdjacent(Vertex* idVertice);
    int getGraoVertex();
    std::vector<Vertex *> getAllAdjacents();
    bool vertexIsVisited();
    void setVisited();
    void setNotVisited();
private:
    int ID;
    bool isVisited;
    std::vector<Vertex*> adjacent;
protected:
};
}
#endif // VERTEX_H
