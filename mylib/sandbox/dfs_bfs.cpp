#include <iostream>
#include <bits/stdc++.h>
// #include <unistd.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;


vector<vector<int>> g(100);
vector<bool> visited(100, false);

void dfs(vector<vector<int>> g, int v) {
  visited[v] = true;
  printf("%d\n", v);
  for(auto node: g[v]) {
    if(!visited[node]) dfs(g, node);
  }
}

queue<int> q;
void bfs(vector<vector<int>> g, int v) {
  q.push(v);
  visited[v] = true;

  while(q.size()) {
    for(auto node: g[q.front()]) {
      // printf("q.front: %d, node: %d\n", q.front(), node);
      if(!visited[node]) {
        q.push(node);
        visited[node] = true;
      }
      // usleep(1000000);
    }
    printf("%d\n", q.front());
    q.pop();
  }
}


int main(int argc, char const* argv[])
{
  // int n;
  // cin>>n;
  // n = 9;
  // REP(i,n) {
  //   int u, v;
  //   cin>>u>>v;
  // }

  g[1].push_back(2);
  g[1].push_back(3);
  g[1].push_back(4);
  g[2].push_back(1);
  g[2].push_back(5);
  g[2].push_back(6);
  g[3].push_back(1);
  g[3].push_back(7);
  g[4].push_back(1);
  g[5].push_back(2);
  g[5].push_back(8);
  g[6].push_back(2);
  g[6].push_back(8);
  g[7].push_back(3);
  g[8].push_back(5);
  g[8].push_back(9);
  g[9].push_back(8);

  printf("===dfs===\n");
  dfs(g,1);
  visited = vector<bool>(100, false);
  printf("===bfs===\n");
  bfs(g,1);

  return 0;
}

