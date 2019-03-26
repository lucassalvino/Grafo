#include <iostream>
#include <stdio.h>
#include "graphutils.h"

using namespace BaseGraph;
using namespace std;
int main(void)
{
    Graph grafo;

    grafo.addEdge(0, 1, 1, -1, true);
    grafo.addEdge(0, 2, 1, -1, true);
    grafo.addEdge(2, 1, 2, -1, true);
    grafo.addEdge(3, 1, 5, -1, true);
    grafo.addEdge(3, 2, 4, -1, true);
    GraphUtils utils;
    int * vet = utils.dijkstra(0, &grafo);
    for(int i = 0; i<grafo.getNumVertex(); i++){
        printf("%d ", vet[i]);
    }
    return 0;
}
