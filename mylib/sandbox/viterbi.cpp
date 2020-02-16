#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ld = long double;

// ref: https://mieruca-ai.com/ai/viterbi_algorithm/

vector<string> ps = {"noun","verb","adj","prep"};
vector<ld> pi = {0.6, 0.0, 0.3, 0.1};
vector<vector<ld>> a = {
  {0.2,0.6,0.0,0.2},
  {0.4,0.3,0.2,0.1},
  {0.5,0.0,0.2,0.3},
  {0.7,0.0,0.3,0.0}
};
vector<string> os = {"John","has","fried","chicken","for","dinner"};
map<string,int> om = {{"John",0},{"has",1},{"fried",2},{"chicken",3},{"for",4},{"dinner",5}};
vector<vector<ld>> o = {
  {0.4,0.0,0.0,0.3,0.0,0.3}, // noun
  {0.0,0.7,0.3,0.0,0.0,0.0}, // verb
  {0.0,0.0,1.0,0.0,0.0,0.0}, // adj
  {0.0,0.0,0.0,0.0,1.0,0.0}  // prep
};

ld log_(ld p) {
  return log2(p+1);
}

ld f(ld p, ld o) {
  return log_(p) + log_(o);
}
ld f(ld p, ld a, ld o) {
  return log_(p) + log_(a) + log_(o);
}

int main(int argc, char const* argv[])
{
  bool debug = false;
  // (遷移確率)*(単語の出現確率) を考えて、最尤パスを求める。
  // log(p+1)の形にしてsumを取ることで実現する。
  // "John has fried chicken for dinner"
  // noun, verb, adj, prep
  // の中で考える
  // delta[t][i]: 時刻tにおいて状態iである最大尤度時の確率
  // psi[t][i]: 時刻tにおいて状態iである最大尤度時の前の状態

  // 1.初期確率からdelta[0][i]を求める。psi[0][i]=-1に設定する
  vector<vector<ld>> delta(os.size(), vector<ld>(ps.size()));
  vector<vector<int>> psi(os.size(), vector<int>(ps.size()));
  REP(i,ps.size()) {
    delta[0][i] = f(pi[i], o[i][om[os[0]]]);
    psi[0][i] = -1;
    if(debug) printf("delta[0][%d]: %Lf\n", i,delta[0][i]);
    if(debug) printf("psi[0][%d]: %d\n", i,psi[0][i]);
  }
  // 2. delta[t+1][j] = max_i(log_(delta[t][i]) + log_(a[i][j]) + log_(o[j][om[os[t+1]]]))
  REP(t,os.size()-1)REP(j,ps.size()) {
    pair<int,ld> max_(-1,-1.0); // (id, log_probability)
    REP(i,ps.size()) {
      ld tmp = f(delta[t][i], a[i][j], o[j][om[os[t+1]]]);
      if(debug) printf("delta[%d][%d]:%Lf, a[%d][%d]:%Lf, o[%d][%d]:%Lf\n", t,i,delta[t][i],i,j,a[i][j],j,om[os[t+1]],o[j][om[os[t+1]]]);
      if(max_.second<tmp) max_ = make_pair(i,tmp);
    }
    assert(max_.first!=-1);
    delta[t+1][j] = max_.second;
    psi[t+1][j] = max_.first;
  }
  // 3. max_i(delta[os.size()-1][i])から最大尤度の状態kを見つけ、
  //    psi[os.size()-1][k]から逆に辿ることで最尤パスを出力する
  pair<int,ld> max_(-1,-1.0); // (id, log_probability)
  REP(i,ps.size()) {
    ld tmp = delta[os.size()-1][i];
    if(max_.second<tmp) max_ = make_pair(i,tmp);
  }
  vector<int> mlp; // maximum likelihood path
  mlp.push_back(max_.first);
  REP(i,os.size()-1) {
    max_.first = psi[os.size()-1-i][max_.first];
    mlp.push_back(max_.first);
  }
  reverse(ALL(mlp));

  REP(i,os.size()) {
    printf("%s: %s\n", os[i].c_str(), ps[mlp[i]].c_str());
  }

  return 0;
}

