#include "test_traversal.hpp"

#include <iostream>
#include <vector>

#include "Graph.hpp"
#include "Traversal.hpp"


using namespace std;

void try_traversal()
{

    int n, u, v, v1, v2;

    cin >> n >> u >> v;

    Graph g(n, true);

    for (int i = 0; i < n - 1; i++) {
        cin >> v1 >> v2;
        g.addEdge(v1 - 1, v2 - 1);
    }

    g.print();

    cout << "======== DFS ========" << endl;
    DFS dfs_u = DFS(g);
    dfs_u.traverse(u - 1);
    vector<int> dfs_dist_u;
    dfs_dist_u = dfs_u.get_distance();

    DFS dfs_v = DFS(g);
    dfs_v.traverse(v - 1);
    vector<int> dfs_dist_v;
    dfs_dist_v = dfs_v.get_distance();

    dfs_u.print();
    cout << "\n\n";
    dfs_v.print();


    cout << "======== BFS ========" << endl;

    BFS bfs_u = BFS(g);
    bfs_u.traverse(u - 1);
    vector<int> bfs_dist_u;
    bfs_dist_u = bfs_u.get_distance();

    BFS bfs_v = BFS(g);
    bfs_v.traverse(v - 1);
    vector<int> bfs_dist_v;
    bfs_dist_v = bfs_v.get_distance();

    bfs_u.print();
    cout << "\n\n";
    bfs_v.print();
}