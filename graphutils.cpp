#include "graphutils.h"


std::list<BaseGraph::Vertex*> BaseGraph::GraphUtils::dijkstra(int origin, int destiny, Graph* graph)
{
    /*########################### Passos de Execução ############################
     * º - Cria um fila de prioriade composta por pares, anexando cada vertice com cada unidade aresta pertecente a ele.
     * º - Seta todos os vertices como não visitado
     * º - Ordena da menor distância
     * º - Inicializa o vetor de distâncias com INT_MAX32 e vetor de ancestrais com -1;
     * º - Define a distancia de origin como 0
     */
    std::priority_queue<std::pair<Vertex *, Edge *> *> prio_queue;
    std::list<Vertex *> listVertexes;
    double dist[graph->getNumVertex()];
    int prev[graph->getNumVertex()];
    Vertex *verifyVertex;

    for (unsigned int i = 0; i < graph->getNumVertex(); i++) {
        graph->getVertexIndex(i)->setNotVisited();
    }

    for (unsigned int i = 0; i < graph->getNumVertex(); i++) {
        dist[i] = INT32_MAX;
        prev[i] = -1;
    }

    dist[origin] = 0;
    listVertexes.push_back(graph->getVertex(origin));

    while(!listVertexes.empty()){
        verifyVertex = listVertexes.front(); //Pega o primeiro vértice da lista
        listVertexes.pop_front(); //Retira o vértice da lista

        if(!verifyVertex->vertexIsVisited()){ // Verifica se ele já foi visitado

            verifyVertex->setVisited(); //Marca o vértice como visitado
            extractMin(&prio_queue,verifyVertex->getId(), graph); //Extrai os pares de arestas e os vértices adjacentes a ele
            while (!prio_queue.empty()) {
                auto pair = prio_queue.top(); //Obtém o menor valor de par (Aresta) da lista de prioridade
                prio_queue.pop(); //Remove o par da lista, pois o mesmo está sendo relaxado!
                if(dist[pair->first->getId()] > (dist[verifyVertex->getId()] + pair->second->getDistance())){//dist[v] > dist[u] + w(u, v)
                   dist[pair->first->getId()] = dist[verifyVertex->getId()] + pair->second->getDistance(); //Atualiza a distancia
                   prev[pair->first->getId()] = verifyVertex->getId(); //prev[u] = v
                   listVertexes.push_back(pair->first);  //Coloca o vértice na fila de análise
                }
            }
        }
    }

    /*
     * Monta a saída do Dijkstra passando o destino para a lista de saída
     * No vetor de ancestrais ele começa obtendo desde o destino fim até o vértice de origem
     * O algoritmo para quando no vetor de ancestrais na ultima posição há o vetor de origem
     */
    std::list<Vertex *> output;
    output.push_back(graph->getVertex(destiny));
    while(true){
        if(output.back()->getId() == origin)
            break;
        std::cout << "ID: " << output.back()->getId() << std::endl;
        output.push_back(graph->getVertex(prev[output.back()->getId()]));
    }

    while(!output.empty()){
        std::cout << "ID: " << output.front()->getId() << std::endl;
        output.pop_front();
    }
    std::list<BaseGraph::Vertex*> a;
    return a;
}

BaseGraph::GraphUtils::~GraphUtils()
{

}

void BaseGraph::GraphUtils::extractMin(std::priority_queue<std::pair<BaseGraph::Vertex *, BaseGraph::Edge *> *> *prio_queue, int vertex, Graph * grafo)
{
    std::vector<Vertex *> a;
    Vertex * dest = nullptr;
    //Obtém a lista de vértices do vertice analisado;
    const std::vector<Vertex *> &lstVertexes = grafo->getVertex(vertex)->getAllAdjacents();

    for (auto it = lstVertexes.begin(); it != lstVertexes.end(); it++) {

        dest = (*it); //Guarda o vertice destino do vertice analisado
        //Cria o par entre vertice origem, e aresta para vertice destino, e guarda no vetor de pares
        prio_queue->push(new std::pair<Vertex *, Edge *>(dest,
                                                         grafo->getEdge(grafo->getVertex(vertex)->getId(),
                                                         dest->getId())));
       }
}
