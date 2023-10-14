#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

/**
 * 最大公約数を返す関数
 */
ll GCD(ll A, ll B) {
  while (A >= 1 && B >= 1) {
    if (A >= B) {
      A = A % B;
    } else {
      B = B % A;
    }
  }
  if (A == 0) {
    return B;
  }
  return A;
}

/**
 * 最小公倍数を返す関数
 */
ll LCM(ll A, ll B) { return (A / GCD(A, B)) * B; }

/**
 * N個の整数の最小公倍数
 * 2つの自然数の最小公倍数
 * 1.aとbの最大公約数をdとする
 * 2.(a * b) / dが最小公倍数
 *
 * 2つの自然数の積はその最小公倍数と最大公約数の積に等しくなる
 * a * b = lcm * gcd
 */
int main() {
  // 入力
  ll N;
  cin >> N;
  vector<ll> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // 処理
  ll R = LCM(A[0], A[1]);
  for (int i = 2; i <= N; i++) {
    R = LCM(R, A[i]);
  }

  // 出力
  cout << R << endl;
}