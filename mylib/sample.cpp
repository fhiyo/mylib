#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;

#define REP(i,n) for(int i=0;i<(n);i++)
#define REP1(i,n) for(int i=1;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
const ll mod = 1e9+7;

template<typename T>
set<T> union_(set<T> ss[])
{
    set<T> res;
    for (size_t i = 0; i < length(ss); i++)
    {
        for (const auto& e: ss[i]) {
            res.insert(e);
        }
    }

    return res;
};

void func(vector<int> vec)
{
    for (size_t i = 0; i < 10; i++)
    {
        vec.push_back(i);
    }
}

int main(int argc, char const *argv[])
{

  cout << (-(ll)(1e9+8))%mod << endl;
  // cout << min(min(3, 2), 3) << endl;

    // set<int> s1, s2;
    // s1.insert(1);
    // s1.insert(2);
    // s1.insert(3);
    // s1.insert(1);
    // s2.insert(4);
    // s2.insert(2);

    // vector<int> v;
    // set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(v));
    // for (const auto& e: v) {
    //     cout << e << " ";
    // }

    // vector<int> v;
    // func(v);
    // for (auto e: v) {
    //     cout << e << " ";
    // }

    // vector<int> v({s1, s2});
    // set<int> a[] = {s1, s2};
    // for (size_t i = 0; i < a.length(); i++)
    // {
    //     cout << i;
    // }
    // for (auto const& e: v) {
    //     cout << e << " ";
    // }
    // set<int> s3 = union_((vector<int>){s1, s2});
    // for (const auto& e: s3) {
    //     cout << e << " ";
    // }
    // cout << "\n";

    return 0;
}
