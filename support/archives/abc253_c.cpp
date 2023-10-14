#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
typedef long long ll; // 9*10^18
typedef unsigned long long ull;
const int INF = 2147483647;
const long long LINF = 1LL << 60;

/** ---  MAIN  ------------------------------------------------------------- */

/**
 * main
 */
int main() {
  // 入力
  int Q;
  map<int, int> S;
  set<int> st;
  cin >> Q;
  rep(i, 0, Q) {
    int type;
    cin >> type;
    if (type == 1) {
      // Sにxを1個追加
      int x;
      cin >> x;
      S[x]++;
      st.insert(x);
    }
    if (type == 2) {
      //
      int x, c;
      cin >> x >> c;
      S[x] -= min(c, S[x]);
      if (S[x] < 0) {
        S[x] = 0;
      }
      if (S[x] == 0) {
        st.erase(x);
      }
    }
    if (type == 3) {
      // max - min
      int mn = *st.begin();
      int mx = *st.rbegin();
      cout << mx - mn << endl;
    }
  }
}