#include <iostream>
#include <vector>

#include "Graph.hpp"


Graph::Graph(int V, bool is_directed)
{
    this->V = V;
    this->is_directed = is_directed;
    adj = new std::vector<int>[V];
}


void Graph::addEdge(int v1, int v2)
{
    adj[v1].push_back(v2);
    if (is_directed) adj[v2].push_back(v1);
}


void Graph::print()
{
    for (auto i = 0; i < V; ++i) {
        for (auto iter = adj[i].begin(); iter != adj[i].end(); ++iter) {
            std::cout << "node: " << i << ", adjacent: " << *iter << std::endl;
        }
    }
}


int Graph::size()
{
    return V;
}


std::vector<int> Graph::adjNode(int node)
{
    return adj[node];
}

std::vector<int> &Graph::operator[] (int idx)
{
    return *(adj + idx);
}
