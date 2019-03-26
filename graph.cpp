#include "graph.h"
BaseGraph::Graph::Graph()
{
    clear();
}

void BaseGraph::Graph::addEdge(Vertex* origin, Vertex* destiny, double distance, int ID, bool updateDistance)
{
    if(ID < 0 || (ID > temp_id_edge)){
        ID = temp_id_edge++;// número de id não foi setado, seta com valor de tem_id_edge
    }
    temp_id_edge = ID+1;//Atualiza ID + 1 para setar proximo ID, caso não exista
    verificaIDEdge(ID);
    Edge add(ID);
    add.setOrigin(origin);
    add.setDestiny(destiny);
    add.setDistance(distance);
    addEdge(add, updateDistance);
}

void BaseGraph::Graph::addVertex(int id)
{
    for(unsigned int i = 0; i < vertex.size(); i++){
        if(vertex[i]->getId() == id)return;
    }
    vertex.push_back(new Vertex(id));
}

BaseGraph::Vertex *BaseGraph::Graph::getVertex(int id, bool add)
{
    for(int i = 0; i < getNumVertex(); i++){
        if(id == vertex[i]->getId()){/*vertex ja existe*/
            return vertex[i];
        }
    }
    if(add){
        Vertex* add = new Vertex(id);
        vertex.push_back(add);
        return add;
    }else{
        return nullptr;
    }
}

void BaseGraph::Graph::addEdge(int origin, int destiny, double distance,int ID, bool bidirectional, bool updateDistance)
{
    addEdge(getVertex(origin, true), getVertex(destiny, true), distance,ID, updateDistance);
    if(bidirectional)
        addEdge(getVertex(destiny, true), getVertex(origin, true), distance);
}

void BaseGraph::Graph::addEdge(Edge value, bool updateDistance){
    Edge* val = getEdge(value.getOrigin()->getId(), value.getDestiny()->getId());
    if (!val){//insert
        addVertex(value.getOrigin()->getId());
        addVertex(value.getDestiny()->getId());
        edges.push_back(value);
    }
    if (val && updateDistance) val->setDistance(value.getDistance());//update distance
}

/*Verifica se existe uma aresta com ID duplicado, caso exista atualiza o valor de ID, para o próximo temp_id_edge
até que o valor de ID não tenha ocorrência no conjunto arestas*/
void BaseGraph::Graph::verificaIDEdge(int &ID)
{
    for(std::vector<Edge>::iterator it = edges.begin(); it!= edges.end(); it++)
        if(ID == it->getId()){
            ID = temp_id_edge++;
            this->verificaIDEdge(ID);
            return;
        }
    return;
}

void BaseGraph::Graph::clear(){
    for(unsigned int i = 0; i < vertex.size(); i++){
        delete [] vertex[i];
    }
    temp_id_edge = 0;
    vertex.clear();
    edges.clear();
}

void BaseGraph::Graph::loadFromFile(std::string source){
    FILE* arq = fopen(source.c_str(), "r");
    if(arq == nullptr) throw std::string("Source ["+source+"] not found");
    int origin, destiny;
    double distance;
    while(fscanf(arq, "%d %d %lf",&origin,&destiny,&distance)!=-1){
        this->addEdge(origin,destiny,distance);
    }
    fclose(arq);
}

void BaseGraph::Graph::saveInFile(std::string source){
    FILE* arq = fopen(source.c_str(), "w");
    if(arq == nullptr) throw std::string("Source ["+source+"] not found");
    std::vector<Edge>::iterator it = edges.begin();
    for(;it != edges.end(); it++){
        int origin, destiny;
        double distance;
        origin = it->getOrigin()->getId();
        destiny = it->getDestiny()->getId();
        distance = it->getDistance();
        fprintf(arq, "%d %d %lf\n",origin,destiny,distance);
    }
    fclose(arq);
}

BaseGraph::Edge* BaseGraph::Graph::getEdge(int origin, int destiny)
{
    std::vector<Edge>::iterator it = edges.begin();
    for(;it != edges.end(); it++){
        if(origin == it->getOrigin()->getId() && destiny == it->getDestiny()->getId()){
            return &(*it);
        }
    }
    return nullptr;
}

BaseGraph::Edge* BaseGraph::Graph::getEdge(Vertex origin, Vertex destiny)
{
    return getEdge(origin.getId(), destiny.getId());
}

BaseGraph::Edge *BaseGraph::Graph::getEdge(int id)
{
    std::vector<BaseGraph::Edge>::iterator it = edges.begin();
    for(int i = 0;it != edges.end();i++, it++){
        if(it->getId() == id)
            return &(*it);
    }
    return nullptr;
}

BaseGraph::Vertex *BaseGraph::Graph::getVertexIndex(int index)
{
    std::vector<BaseGraph::Vertex*>::iterator it = vertex.begin();
    for(int i = 0;it != vertex.end(); it++, i++){
        if(i == index) return *it;
    }
    return nullptr;
}

unsigned int BaseGraph::Graph::getNumEdge()
{
    return edges.size();
}

unsigned int BaseGraph::Graph::getNumVertex()
{
    return vertex.size();
}

double **BaseGraph::Graph::getMatrix()
{
    std::vector<Edge>::iterator it = edges.begin();
    double ** ret = new double*[vertex.size()];
    for(unsigned int i = 0;i < vertex.size();i++) ret[i] = new double[vertex.size()];
    for(unsigned int i = 0;i< vertex.size();i++)
        for(unsigned int j = 0; j< vertex.size();j++)
            ret[i][j] = std::numeric_limits<double>::max();
    for(; it != edges.end(); it++){
        ret[it->getOrigin()->getId()][it->getDestiny()->getId()] = it->getDistance();
    }
    return ret;
}
