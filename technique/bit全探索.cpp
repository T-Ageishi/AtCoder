#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
/* MAIN ************************************************** */

ll euc(ll c, ll d) {
  if (d == 0) {
    return c;
  } else if (c == 0) {
    return d;
  }
  if (c > d) {
    return euc(d, c % d);
  } else {
    return euc(c, d % c);
  }
}

/**
 * main
 */
int main() {
  // 入力
  int N;
  cin >> N;

  for (int bit = 0; bit < (1 << N); bit++) {
    // いくつか選ぶ方法を10進数で表したものに対して処理
    /**
     * とはいっても10進数の値が表している「いくつか選ぶ方法」が
     * 何を選んだのかが分からないので、逆のことを行って復元する。
     * つまり、
     * ・10進数0, 1, 2,..., 2^N - 1を再び2進数で表す
     * ・1 <= i <= Nを満たすiについて、2進数で表される「いくつか選ぶ方法」から
     * 「i番目のものを選んだかどうか」を判定する
     */
    for (int i = 0; i < N; i++) {
      if ((bit >> i) & 1) {  // 判定したいiビット目が一桁目になる
        // 選んだものに対して処理
      }
    }
  }
}