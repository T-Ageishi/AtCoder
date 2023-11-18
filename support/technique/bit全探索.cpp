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
  cin >> N;

  for (int bit = 0; bit < (1 << N); bit++) {  // bitで組み合わせを列挙
    for (int i = 0; i < N; i++) {
      // iビット目でフラグが立っているかを調べる
      if (bit & (1 << i)) {
        // iビット目が1だったのでフラグが立っている
      }
    }
  }
}