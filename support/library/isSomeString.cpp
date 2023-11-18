#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
#define rep(i, b)     for (int i = 0; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
const ll infl = 1LL << 60;
const int inf = (INT_MAX / 2) * 2;
const string yes = "Yes";
const string no = "No";

/** ------------------------------------------------------------------ */
/**
 * tがsの部分列か
 */
bool is_some_string(string s, string t) {
  if (s.size() != t.size() + 1) return false;
  int si = 0;
  for (int ti = 0; ti < (int)t.size(); ti++) {
    while (si < (int)s.size() && s[si] != t[ti]) si++;
    if (si == (int)s.size()) return false;
    si++;
  }
  return true;
}

int main() {
  string s, t;
  cin >> s >> t;
  if (is_some_string(s, t)) cout << yes << endl;
  else cout << no << endl;
}
