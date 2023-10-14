#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
/********************************************************* */
// ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
// ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

/* MAIN ************************************************** */

/**
 * std::stable_sort
 * ランレングス圧縮
 * 構築問題の典型テクとして「理論値の最大値を実はいつも達成可能」
 */
int main() {
  // 入力
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, 0, n) cin >> a[i];

  // 処理
  ll left = 0, right = 1000000000;
  auto check = [&](ll mid) -> bool {
    // 答えがmid以下かを判定する
    ll sum = 0;
    rep(i, 0, n) sum += mid / a[i];
    if (sum >= k) return true;
    else return false;
  };
  while (left <= right) {
    ll mid = (left + right) / 2;
    if (check(mid)) right = mid - 1;
    else left = mid + 1;
  }
  cout << left << endl;
}