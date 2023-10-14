#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/**
 * main
 */
int main() {
  // 入力
  ll N;
  cin >> N;

  // 素因数分解
  bool flg = false;
  for (ll i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      if (flg) cout << " ";
      flg = true;
      N /= i;
      cout << i;
    }
  }
  if (N >= 2) {
    if (flg) cout << " ";
    flg = true;
    cout << N;
  }
  cout << endl;
}