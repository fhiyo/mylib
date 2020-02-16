#include "Traversal.hpp"

#include <iostream>
#include <vector>
#include <queue>


Traverse::Traverse(Graph& g) : g(g)
{
    visited = std::vector<bool>(g.size(), false);
    distance = std::vector<int>(g.size(), 0);
};


DFS::DFS(Graph& g) : Traverse(g) {};


void DFS::traverse(int v)
{
    _traverse(v, 0);
}


void DFS::_traverse(int v, int num)
{
    if (!visited[v]) {
        visited[v] = true;
        distance[v] = num;
        for (const auto& node: g.adjNode(v)) {
            _traverse(node, num + 1);
        }
    }
}

void DFS::print()
{
    for (std::vector<int>::iterator it = distance.begin(); it != distance.end(); ++it) {
        std::cout << "idx: " << std::distance(distance.begin(), it) << ", distance: " << *it << std::endl;
    }
}


std::vector<int> DFS::get_distance()
{
    return distance;
}


BFS::BFS(Graph& g) : Traverse(g) {};


void BFS::traverse(int s)
{
    int num = 0;
    std::queue<int> outer, inner;
    outer.push(s);
    while (!outer.empty()) {
        while (!outer.empty()) {
            inner.push(outer.front());
            visited[outer.front()] = true;
            distance[outer.front()] = num;
            outer.pop();
        }
        while (!inner.empty()) {
            for (const auto& node: g[inner.front()]) {
                if (!visited[node]) outer.push(node);
            }
            inner.pop();
        }
        num++;
    }
}


void BFS::print()
{
    for (std::vector<int>::iterator it = distance.begin(); it != distance.end(); ++it) {
        std::cout << "idx: " << std::distance(distance.begin(), it) << ", distance: " << *it << std::endl;
    }
}


std::vector<int> BFS::get_distance()
{
    return distance;
}
