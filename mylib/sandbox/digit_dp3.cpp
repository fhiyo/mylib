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

// 桁, 指定する桁の和, tight
ll dp[101][1001][2];

int main(int argc, char const* argv[])
{
  // XXX(2020/02/11): 間違っているので注意！
  string s;
  cin>>s;
  int d;
  cin>>d;

  dp[0][0][0] = 1;
  REP(i,s.size())REP(j,d+1) {
    int n = s[i]-'0';
    if(j-n>=0) dp[i+1][j][0] = dp[i][j-n][0];
    else dp[i+1][j][0] = 0;

    ll tmp = 0;
    REP(nj,10)REP(nk,2) {
      tmp += j-nj>=0 ? dp[i][j-nj][nk] : 0;
    }
    dp[i+1][j][1] = tmp;

    printf("dp[%lld][%lld][%lld]: %lld\n", i+1, j, 0, dp[i+1][j][0]);
    printf("dp[%lld][%lld][%lld]: %lld\n", i+1, j, 1, dp[i+1][j][1]);
  }

  ll ans = dp[s.size()][d][0] + dp[s.size()][d][1];
  cout << ans << endl;

  return 0;
}

