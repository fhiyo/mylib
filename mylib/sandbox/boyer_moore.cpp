// boyer_moore algorithm's implementation (only bad character rule)
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define rep1(i,n) for(int i=1;i<(n);i++)
#define all(a)  (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int, int>;
const ll mod = 1e9+7;

map<char, int> get_skip_table(string pattern) {
  int index = 0;
  map<char, int> t;
  reverse(pattern.begin(), pattern.end());
  for(auto c: pattern) {
    if(!t[c]) t[c] = index;
    index++;
  }
  return t;
}

int get_skip_count(map<char, int> table, char c, int pattern_length, int match_position) {
  int skip;
  if(table.find(c) == table.end()) skip = pattern_length;
  else skip = table[c];
  skip -= match_position;
  if(skip <= 0) skip = 1;
  return skip;
}

vector<int> boyer_moore(string text, string pattern) {
  map<char, int> skip_table = get_skip_table(pattern);
  vector<int> match_indexes;
  int index = 0;
  int limit = text.length() - pattern.length() + 1;
  while(index < limit) {
    string part_text = text.substr(index, pattern.length());
    int pattern_last_index = pattern.length() - 1;

    bool match = true;
    int j = pattern_last_index;
    char c;
    int match_position = 0;

    while(j>=0 && match) {
      if(j > part_text.length() - 1) {
        match = false;
      } else {
        c = part_text[j];
        if(c!=pattern[j]) match = false;
        j--;
      }
    }

    if(match) match_indexes.push_back(index);
    int skip = get_skip_count(skip_table, c, pattern.length(), match_position);
    index += skip;
  }

  return match_indexes;
}


void f(string text, string pattern, string expected) {
  vector<int> indexes = boyer_moore(text, pattern);
  cout << "expected: " << expected << endl;
  printf("actual: ");
  for(auto e: indexes) printf("%d ", e); printf("\n");
  printf("\n");
}


int main(int argc, char const* argv[])
{

  f("abacadabrabracabracadabrabrabracad", "rab", "8 23 26");
  f("abacadabrabracabracadabrabrabracad", "ccccc", "");
  f("abacadabrabracabracadabrabrabracad", "aba", "0");
  f("abacadabrabracabracadabrabrabracad", "abacadabrabracabracadabrabrabracad", "0");
  f("abacadabrabracabracadabrabrabracad", "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa", "");
  f("abacadabrabracabracadabrabrabracad", "cad", "3 18 31");
  f("", "cad", "");
  f("abracadbra", "a", "0 3 5 9");
  f("a", "a", "0");
  // f("abcd", "", "");  // patternが空文字の場合の処理は実装してない

  return 0;
}

