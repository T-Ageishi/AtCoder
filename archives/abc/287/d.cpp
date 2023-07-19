#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
#define rep(i, a, b) for (int i = a; i < b; i++)
/* MAIN ************************************************** */

/**
 * std::stable_sort
 */
int main() {
  // 入力
  string s, t;
  cin >> s >> t;

  // 処理
  int s_len = s.size(), t_len = t.size();
  vector<bool> pre(s.size() + 1, false), suf(s.size() + 1, false);

  auto match_or_not = [](char a, char b) {
    return a == '?' || b == '?' || a == b;
  };

  pre[0] = true;
  for (int i = 0; i < (int)t.size(); i++) {
    if (!match_or_not(s[i], t[i])) break;
    pre[i + 1] = true;
  }

  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());

  suf[0] = true;
  for (int i = 0; i < (int)t.size(); i++) {
    if (!match_or_not(s[i], t[i])) break;
    suf[i + 1] = true;
  }

  for (int i = 0; i <= (int)t.size(); i++) {
    if (pre[i] && suf[(int)t.size() - i]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
}