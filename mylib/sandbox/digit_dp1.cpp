// ref: https://triple-four.hatenablog.com/entry/2018/09/22/213655
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

int rec(string s, int k=0, bool tight=true) {
  // 見てる桁がsの桁を超えたらcount 1を返す
  if(k==s.size()) return 1;
  // 今見ている桁のdigit
  int x = s[k] - '0';
  // 今見ている桁の見るべき最大値
  int l = tight ? x : 9;
  int res = 0;
  REP(i,l+1) {
    // REP(j,k)printf("  ");
    // printf("k:%d, i:%d, l:%d\n", k, i, l);
    res += rec(s, k+1, tight && i==l);
  }
  // REP(j,k)printf("  ");
  // printf("res:%i\n", res);
  return res;
}

int main(int argc, char const* argv[])
{
  string s;
  cin>>s;

  int ans = rec(s) - 1;
  cout << ans << endl;

  return 0;
}



// #include <iostream>
// #include <bits/stdc++.h>
//
// using namespace std;
//
// #define REP(i,n) for(int i=0;i<(n);i++)
// #define REP1(i,n) for(int i=1;i<(n);i++)
// #define ALL(a)  (a).begin(),(a).end()
// using ll = long long;
// using ld = long double;
// using Pint = pair<int, int>;
// const ll mod = 1e9+7;
//
// int rec(string& s, int k=0, bool tight=true) {
//   if(k==s.size()) return 1;
//   int x = s[k]-'0';
//   int r = tight ? x : 9;
//   REP(i,k) printf("  ");
//   printf("k:%d, r:%d, tight:%d\n", k, r, tight);
//   int res = 0;
//   REP(i,r+1) {
//     // 「今の」桁のdigitがiのときの題意を満たす数の総数
//     REP(j,k) printf("  ");
//     printf("i:%d\n", i);
//     res += rec(s, k+1, tight && i==r);
//   }
//
//   REP(i,k) printf("  ");
//   printf("res:%d\n", res);
//   return res;
// }
//
// int main(int argc, char const* argv[])
// {
//   string s;
//   cin>>s;
//
//   cout << rec(s) - 1 << endl;
//
//   return 0;
// }

