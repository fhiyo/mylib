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
using Matrix = vector<vector<int>>;
const int INF = 1001001001;

void warshall_floyd(Matrix &costs) {
  REP(i,costs.size())REP(j,costs.size()) {
    if(i==j) costs[i][j] = 0;
    else if(!costs[i][j]) costs[i][j] = INF;
  }
  REP(i,costs.size())REP(j,costs.size())REP(k,costs.size()) {
    // ref: 蟻本p.98 ワーシャルフロイド法
    // (負閉路が存在しない場合)最短経路は頂点kを使うか使わないかのどちらか。
    // 頂点0~kまでを使用したiからjまでの最短経路をdp[k][i][j]とおくと、
    // dp[k][i][j] = min(dp[k-1][i][j], dp[k-1][i][k]+dp[k-1][k][j]);
    // である。このdpは同じ配列を使い回せるので、以下のように実装できる。
    if((costs[i][k]!=INF) && (costs[k][j]!=INF)) costs[i][j] = min(costs[i][j], costs[i][k]+costs[k][j]);
  }
}

int main(int argc, char const* argv[])
{
  int n, m;
  cin>>n>>m;

  Matrix costs(n, vector<int>(n));
  REP(i,m) {
    int f, t, c;
    cin>>f>>t>>c;
    costs[f][t] = c;
  }

  // 使わない
  int src, dest;
  cin>>src>>dest;

  warshall_floyd(costs);
  // 負閉路がある場合、最短が求まる場合と求まらないときがあるが、このプログラムでは確認していない
  REP(i,n)REP(j,n) {
    printf("(%d,%d): %d\n", i,j,costs[i][j]);
  }

  return 0;
}

