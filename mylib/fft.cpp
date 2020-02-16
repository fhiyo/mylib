#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(int i=0;i<(n);i++)
#define ALL(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

class FTT {
private:
  static void dft(vector<complex<ld>>& f, int inv) {
    // inv: 1 or -1
    int size = f.size();
    if(size == 1) return;
    vector<complex<ld>> f0, f1;
    REP(i,size/2) {
      f0.push_back(f[2*i]);
      f1.push_back(f[2*i+1]);
    }
    dft(f0, inv); dft(f1, inv);
    complex<ld> x = 1;  // f(\zeta_n^i) = f_0(\zeta_{n/2}^i) + \zeta_n^i*f_1(\zeta_{n/2}^i) の\zeta_n^i
    complex<ld> zeta = polar(1.0, inv*2.0*M_PI/size);
    REP(i,size) {
      f[i] = f0[i%(size/2)] + x * f1[i%(size/2)];
      // cout << "size: " << size << ", f[" << i << "]: (" << f[i].real() << ", " << f[i].imag() << ")  angle: " << arg(f[i])*180.0/M_PI   << endl;
      x *= zeta;
    }
  }

public:
  template<typename T>
    static vector<ld> multiply(vector<T> f, vector<T> g) {
      vector<complex<ld>> nft_f, nft_g;
      int size = 1;
      while(size < f.size()+g.size()) size *= 2;
      nft_f.resize(size); nft_g.resize(size);
      REP(i,f.size()) {
        nft_f[i] = f[i];
        nft_g[i] = g[i];
      }
      dft(nft_f, 1); dft(nft_g, 1);
      REP(i,size) nft_f[i] *= nft_g[i]; // \hat{f*g}(t) fとgの積に対するDFT
      dft(nft_f, -1); // (f*g)(x)の各係数がnft_fに入る (名前がわかりにくいが)
      vector<ld> res;
      REP(i,size) res.push_back(nft_f[i].real()/size);

      return res;
    }
};

int main(int argc, char const* argv[])
{
  int n;
  cin >> n;

  vector<ll> f, g;
  REP(i,n) {
    ll a, b;
    cin >> a >> b;
    f.push_back(a);
    g.push_back(b);
  }

  vector<long double> res = FTT::multiply(f, g);

  cout << 0 << endl;
  for (int i = 0; i < 2*n-1; i++) {
    cout << llround(res[i]) << endl;
  }

  return 0;
}


// ref: https://qiita.com/ageprocpp/items/0d63d4ed80de4a35fe79
// class FastFourierTransform {
// private:
//     static void dft(vector<complex<long double>>& func, int inverse) {
//         int sz = func.size();
//         if (sz == 1)return;
//         vector<complex<long double>> veca, vecb;
//         REP(i, sz / 2) {
//             veca.push_back(func[2 * i]);
//             vecb.push_back(func[2 * i + 1]);
//         }
//         dft(veca, inverse); dft(vecb, inverse);
//         complex<long double> now = 1, zeta = polar(1.0, inverse * 2.0 * acos(-1) / sz);
//         REP(i, sz) {
//             func[i] = veca[i % (sz / 2)] + now * vecb[i % (sz / 2)];
//             now *= zeta;
//         }
//     }
// public:
//     template<typename T>
//     static vector<long double> multiply(vector<T> f, vector<T> g) {
//         vector<complex<long double>> nf, ng;
//         int sz = 1;
//         while (sz < f.size() + g.size())sz *= 2;
//         nf.resize(sz); ng.resize(sz);
//         REP(i, f.size()) {
//             nf[i] = f[i];
//             ng[i] = g[i];
//         }
//         dft(nf, 1);
//         dft(ng, 1);
//         REP(i, sz)nf[i] *= ng[i];
//         dft(nf, -1);
//         vector<long double> res;
//         REP(i, sz)res.push_back(nf[i].real() / sz);
//         return res;
//     }
// };


