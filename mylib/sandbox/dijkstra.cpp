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
  Edge(int to, int cost): to(to), cost(cost) {}
};

struct Node {
  int current_cost, next;
  bool checked;
  Node(int ccost, int next, bool checked): current_cost(ccost), next(next), checked(checked) {}
};

// priority_queueを用いる
void dijkstra(vector<vector<Edge>> &g, vector<Node> &v, int s) {
  v[s] = Node(0,-1,true);
  // 1~nのindexに情報を格納しているので-1する
  REP(i,v.size()-1) {
    priority_queue<Pint, vector<Pint>, greater<Pint>> q;
    for(auto edge: g[s]) {
      int nid = edge.to;
      if(!v[nid].checked) {
        v[nid].current_cost = min(v[nid].current_cost, v[s].current_cost + edge.cost);
        q.emplace(nid, v[nid].current_cost);
      }
    }
    if(!q.size()) break;
    v[q.top().first].next = s;
    v[q.top().first].checked = true;
    s = q.top().first;
    q.pop();
  }
}

void dijkstra2(vector<vector<Edge>> &g, vector<Node> &v, int s) {
  v[s] = Node(0,-1,true);
  // 1~nのindexに情報を格納しているので-1する
  REP(i,v.size()-1) {
    Pint min_node(0,1001001001); // (id, cost)
    for(auto edge: g[s]) {
      // printf("edge to:%d, cost:%d\n", edge.to, edge.cost);
      int nid = edge.to;
      if(!v[nid].checked) {
        v[nid].current_cost = min(v[nid].current_cost, v[s].current_cost + edge.cost);
        if(min_node.second > v[nid].current_cost) {
          min_node.first = nid;
          min_node.second = v[nid].current_cost;
        }
      }
    }
    if(min_node.first==0) break;
    v[min_node.first].checked = true;
    v[min_node.first].next = s;
    s = min_node.first;
  }
}

int main(int argc, char const* argv[])
{
  vector<vector<Edge>> g(6);
  g[1].emplace_back(2,1);
  g[1].emplace_back(5,8);
  g[2].emplace_back(1,1);
  g[2].emplace_back(3,2);
  g[2].emplace_back(4,5);
  g[2].emplace_back(5,6);
  g[3].emplace_back(2,2);
  g[3].emplace_back(4,1);
  g[3].emplace_back(5,7);
  g[4].emplace_back(2,5);
  g[4].emplace_back(3,1);
  g[4].emplace_back(5,1);
  g[5].emplace_back(1,8);
  g[5].emplace_back(2,6);
  g[5].emplace_back(3,7);
  g[5].emplace_back(4,1);

  for(vector<vector<Edge>>::iterator it=g.begin(); it!=g.end(); it++) {
    printf("id:%d ", it-g.begin());
    for(auto edge: *it) {
      printf("(%d,%d) ", edge.to, edge.cost);
    } printf("\n");
  }

  vector<Node> v(6, Node(1001001001,-1,false));

  dijkstra(g, v, 1);

  for(vector<Node>::iterator it=v.begin(); it!=v.end(); it++) {
    printf("id: %d, cost: %d, next: %d, checked: %d\n", it-v.begin(), it->current_cost, it->next, it->checked);
  }

  return 0;
}

