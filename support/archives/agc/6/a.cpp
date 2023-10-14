#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
/* MAIN ************************************************** */

/**
 * main
 */
int main() {
  // 入力
  int N;
  string s, t;
  cin >> N >> s >> t;

  string ans = s + t;
  for (int i = 0; i < N; i++) {
    // s[i]にt[0]を重ねる
    if (s[i] != t[0]) continue;
    string tmp = s.substr(0, i) + t;
    if (tmp.substr(0, N) == s && tmp.substr((int)tmp.size() - N) == t) {
      ans = tmp;
      break;
    }
  }
  cout << (int)ans.size() << endl;
}