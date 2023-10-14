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
 * https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_cl
 */
int main() {
  // 入力
  int n, k;
  cin >> n >> k;
  vector<int> a(n + 1);
  rep(i, 1, n + 1) cin >> a[i];

  vector<int> csum(n + 1);
  csum[1] = a[1];
  rep(i, 2, n + 1) csum[i] = csum[i - 1] + a[i];

  // しゃくとり法
  vector<int> r(n + 1);
  rep(i, 1, n + 1) {
    // 商品iから連続する商品を購入するとする
    if (i == 0) r[i] = 0;
    else r[i] = r[i - 1];

    // 延ばす
    while (true) {
      if (r[i] >= n) break;
      if (csum[r[i] + 1] - csum[i - 1] <= k) {
        r[i]++;
      } else {
        break;
      }
    }
  }
  ll ans = 0;
  for (int i = 1; i <= n; i++) ans += (r[i] - i + 1);
  cout << ans << endl;
}