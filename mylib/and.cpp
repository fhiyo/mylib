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
  // int i = 14 & 3;
  int i = 14 | 3;
  i |= 2;
  i &= 3;
  cout << i << endl;

  return 0;
}

