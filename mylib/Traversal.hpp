#ifndef __TRAVERSAL_HPP__
#define __TRAVERSAL_HPP__

#include "Graph.hpp"

#include <vector>


class Traverse
{
protected:
    Graph& g;
    std::vector<bool> visited;
    std::vector<int> distance;

public:
    Traverse(Graph& g);
    virtual void traverse(int v) = 0;
    virtual void print() = 0;
    virtual std::vector<int> get_distance() = 0;
};


class DFS : public Traverse
{
private:
    void _traverse(int v, int num);

public:
    DFS(Graph& g);
    void traverse(int v);
    void print();
    std::vector<int> get_distance();
};


class BFS : public Traverse
{
public:
    BFS(Graph& g);
    void traverse(int s);
    void print();
    std::vector<int> get_distance();
};


#endif