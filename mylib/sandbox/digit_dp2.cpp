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

ll memo[100][1000][2];

ll rec(string s, int rest, int k=0, bool tight=true) {
  if(rest<0) return 0;
  // 残りの桁の数は全部0だけ
  if(!rest) return 1;
  // // 探索し切ったけど当てはまらなかった
  if(k==s.size()) return 0;

  int x = s[k] - '0';
  int l = tight ? x : 9;
  ll &res = memo[k][rest][tight];
  if(~res) return res;
  res = 0;
  REP(i,l+1) {
    if(rest-i<0) break;
    // REP(j,k) printf("  "); printf("k:%d, i:%d, rest-i:%d, l:%d\n", k, i, rest-i, l);
    res += rec(s, rest-i, k+1, tight && i==l) % mod;
    res%=mod;
  }
  // REP(j,k) printf("  "); printf("res:%d\n", res);
  return res;
}

int main(int argc, char const* argv[])
{
  string s;
  cin>>s;
  int d;
  cin>>d;

  memset(memo, -1, sizeof(memo));

  ll ans = rec(s, d);
  cout << ans << endl;

  return 0;
}

