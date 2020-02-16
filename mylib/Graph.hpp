#ifndef __GRAPH_HPP__
#define __GRAPH_HPP__

#include <vector>


class Graph
{
    int V;
    bool is_directed;
    std::vector<int> *adj;

public:
    Graph(int V, bool is_directed);
    void addEdge(int v1, int v2);
    void print();
    int size();
    std::vector<int> adjNode(int node);

    std::vector<int> &operator[] (int idx);
};


#endif
