#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i > b; i--)
/********************************************************* */
ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/* MAIN ************************************************** */

/**
 * std::stable_sort
 * ランレングス圧縮
 * std::lcm(c, d) : cとdの最小公倍数
 */
int main() {
  // 入力
  int N, X;
  cin >> N >> X;
  int min_dist = INF;  // Xから一番近い都市への距離
  vector<int> co(N);
  rep(i, 0, N) {
    cin >> co[i];
    min_dist = min(min_dist, abs(co[i] - X));
  }

  // 処理
  int ans = 0;
  rep(i, 0, N) ans = gcd(ans, abs(co[i] - X));
  cout << ans << endl;
}