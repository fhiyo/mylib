#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using Pair = pair<int, int>;
const ll mod = 1e9 + 7;

int main(int argc, char const* argv[])
{
  // vector<int> v({10, 20, 20, 30});
  //
  // int ub = upper_bound(v.begin(), v.end(), 30) - v.begin();
  // cout << "upper_bound: " << ub << endl;

  vector<pair<int, int>> v;
  v.emplace_back(10, 100);
  v.emplace_back(20, 0);
  v.emplace_back(20, 10);
  v.emplace_back(30, 5);
  // int ub = upper_bound(v.begin(), v.end(), pair<int,int>(30, -1)) - v.begin();
  int ub = upper_bound(v.begin(), v.end(), pair<int,int>(30, 5)) - v.begin();
  cout << "upper_bound: " << ub << endl;

  return 0;
}

