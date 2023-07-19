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
 * https://atcoder.jp/contests/abc247/tasks/abc247_d
 * http://vivi.dyndns.org/tech/cpp/deque.html
 */
int main() {
  // 入力
  int q;
  cin >> q;
  deque<pair<ll, ll>> dq; // 数, 個数
  rep(i, 0, q) {
    int type;
    cin >> type;
    if (type == 1) {
      // xが書かれたボールを右側からc個入れる
      ll x, c;
      cin >> x >> c;
      if (dq.empty()) {
        dq.push_back({x, c});
        continue;
      }
      pair<ll, ll> bk = dq.back();
      if (bk.first == x) {
        bk.second += c;
        dq.pop_back();
        dq.push_back(bk);
      } else {
        dq.push_back({x, c});
      }
    }
    if (type == 2) {
      // 左側からボールをc個取り出し、和を求める
      ll c, ans = 0;
      cin >> c;
      while (c > 0) {
        pair<ll, ll> fr = dq.front();
        if (fr.second == c) {
          ans += fr.first * c;
          dq.pop_front();
          break;
        }
        if (fr.second > c) {
          ans += fr.first * c;
          fr.second -= c;
          dq.pop_front();
          dq.push_front(fr);
          break;
        }
        if (fr.second < c) {
          ans += fr.first * fr.second;
          dq.pop_front();
          c -= fr.second;
        }
      }
      cout << ans << endl;
    }
  }
}