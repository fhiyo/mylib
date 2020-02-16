#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

struct Edge {
  int to, cost;
  Edge(int to, int cost): to(to),cost(cost) {}
};

using AdjList = vector<vector<Edge>>;
const int INF = 1001001001;

bool bellman_ford(AdjList &g, vector<int> &costs, int s) {
  costs[s] = 0;
  for(int i=0; i<g.size(); i++) {
    // n stepかければ探索するパスの長さはnになり、それはグラフ全体を覆うことができる (負閉路あっても？)
    for(int j=0; j<g.size(); j++) {
      for(int k=0; k<g[j].size(); k++) {
        Edge edge = g[j][k];
        // INF > INF + (-|cost|)は真なので、負のコストがあるときにINF同士で計算すると変な場合にコストが更新されることがある
        if(costs[j] != INF && costs[edge.to] > costs[j]+edge.cost) {
          costs[edge.to] = costs[j]+edge.cost;
          if(i==g.size()-1) return true;
        }
      }
    }
  }
  return false;
}

int main(int argc, char const* argv[])
{
  int n, m;
  cin>>n>>m;

  AdjList g(n);
  // 0-index
  // from, to, cost
  REP(i,m) {
    int f, t, c;
    cin>>f>>t>>c;
    g[f].emplace_back(t, c);
  }

  // src, dest
  int src, dest;
  cin>>src>>dest;

  vector<int> costs(n,INF);
  bool res = bellman_ford(g, costs, src);
  if(res) cout << "negative loop" << endl;
  // 負閉路がある場合、最短が求まる場合と求まらないときがあるが、このプログラムでは確認していない
  cout << costs[dest] << endl;

  // for(int i=0; i<n; i++) {
  //   for(auto e: g[i]) {
  //     printf("(%d,%d,%d)\n", i, e.to, e.cost);
  //   }
  // }

  return 0;
}

