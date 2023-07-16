#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
#define _GLIBCXX_DEBUG
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i > b; i--)
/* MAIN ************************************************** */

void rle(string s, vector<pair<char, int>> &vec) {
  int cnt = 1;
  for (int i = 1; i < (int)s.size(); i++) {
    if (s[i] != s[i - 1]) {
      vec.push_back({s[i - 1], cnt});
      cnt = 0;
    }
    cnt++;
  }
  vec.push_back({s.back(), cnt});
}

/**
 * std::stable_sort
 * ランレングス圧縮
 */
int main() {
  // 入力
  string s, t;
  cin >> s >> t;

  // 処理
  vector<pair<char, int>> svec, tvec;
  rle(s, svec), rle(t, tvec);
  if (svec.size() != tvec.size()) {
    cout << "No" << endl;
    return 0;
  }

  bool ans = true;
  for (int i = 0; i < svec.size(); i++) {
    if (svec[i].first != tvec[i].first) ans = false;
    if (!(svec[i].second == tvec[i].second ||
          svec[i].second < tvec[i].second && svec[i].second >= 2))
      ans = false;
  }
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}