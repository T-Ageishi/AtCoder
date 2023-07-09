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
  ll T;
  cin >> T;

  // 処理
  rep(i, 0, T) {
    ll N;
    cin >> N;

    ll p = 0, q = 0;
    for (ll i = 2; i * i * i <= N; i++) {
      if (N % i != 0) continue;
      if ((N / i) % i == 0) {
        p = i;
        q = N / i / i;
      } else {
        q = i;
        p = (ll)round(sqrt(N / i));
      }
      break;
    }

    cout << p << " " << q << endl;
  }
}