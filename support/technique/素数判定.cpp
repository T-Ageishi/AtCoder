#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

bool isPrime(ll N) {
  // Nを2以上の整数とし、Nが素数であればtrue、素数でなければfalse
  for (ll i = 2; i * i <= N; i++) {
    if (N % i == 0) return false;
  }
  return true;
}

/**
 * main
 */
int main() {
  // 入力
  ll N;
  cin >> N;
  for (ll i = 1; i * i <= N; i++) {
    if (N % i != 0) continue;
    cout << i << endl;  // iを約数に追加
    if (i != N / i) {
      cout << N / i << endl;  // N/iも約数に追加
    }
  }
}