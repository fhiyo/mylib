#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

int main(int argc, char const* argv[])
{
  int a=4;
  a<<=1;
  cout << a << endl;
  a<<=1;
  cout << a << endl;
  a>>=1;
  cout << a << endl;
  a>>=1;
  cout << a << endl;

  int b = 1<<0;
  cout << "b: " << b << endl;

  ll c = 1ll<<32;
  cout << "c: " << c << endl;
  ll d = 1<<32;
  cout << "d: " << d << endl;

  return 0;
}

