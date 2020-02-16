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

vector<int> mergesort(vector<int>::iterator begin, vector<int>::iterator end) {
  if(begin==end) return vector<int>();
  int d = end-begin;
  if(d==1) return vector<int>({*begin});

  vector<int>::iterator mid = d/2 + begin;
  vector<int> left = mergesort(begin, mid);
  vector<int> right = mergesort(mid, end);
  vector<int>::iterator l_iter = left.begin();
  vector<int>::iterator r_iter = right.begin();

  vector<int> res;
  while((l_iter!=left.end()) && (r_iter!=right.end())) {
    if(*l_iter <= *r_iter) res.push_back(*(l_iter++));
    else res.push_back(*(r_iter++));
  }
  if(l_iter!=left.end()) {
    while(l_iter!=left.end()) res.push_back(*(l_iter++));
  }
  else {
    while(r_iter!=right.end()) res.push_back(*(r_iter++));
  }
  return res;
}

void debug_print(vector<int> v, int num) {
  printf("v%d: ", num); for(auto e: v) printf("%d ", e); printf("\n");
  vector<int> s = mergesort(v.begin(), v.end());
  printf("s%d: ", num); for(auto e: s) printf("%d ", e); printf("\n");
  printf("\n");
}

int main(int argc, char const* argv[])
{
  vector<int> v1({});
  debug_print(v1, 1);

  vector<int> v2({1});
  debug_print(v2, 2);

  vector<int> v3({1,3,2,10,0,5,6});
  debug_print(v3, 3);

  return 0;
}

