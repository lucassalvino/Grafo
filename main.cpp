#include <iostream>
#include <stdio.h>
#include "graph.h"
using namespace BaseGraph;
using namespace std;
int main(void)
{
    Graph grafo;
    grafo.addEdge(0,1,6, 0);
    grafo.addEdge(0,2,-1, 1);
    grafo.addEdge(1,2,1, 2);
    Edge* teste = grafo.getEdge(2);
    return 0;
}
