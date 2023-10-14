#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
/* MAIN ************************************************** */

/**
 * https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_m
 */
int main() {
  // 入力
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  // しゃくとり法
  vector<int> r(n);
  rep(i, 0, n) {
    // スタート地点を決める
    if (i == 0) r[i] = 0;
    else r[i] = r[i - 1];

    // 到達地点を延ばす
    while (true) {
      if (r[i] == n - 1) break;
      if (a[r[i] + 1] - a[i] <= k) r[i]++;
      else break;
    }
  }

  ll ans = 0;
  rep(i, 0, n) ans += (r[i] - i);
  cout << ans << endl;
}