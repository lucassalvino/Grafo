#include <iostream>
#include <stdio.h>
#include "graphutils.h"

using namespace BaseGraph;
using namespace std;
int main(void)
{
    Graph grafo;
    grafo.addEdge(0, 1, 1, 1);
    grafo.addEdge(0, 2, 1, 1);
    grafo.addEdge(2, 1, 2, 1);
    grafo.addEdge(3, 1, 5, 1);
    grafo.addEdge(3, 2, 4, 1);
    GraphUtils utils;
    utils.dijkstra(0, 1, &grafo);
    return 0;
}
