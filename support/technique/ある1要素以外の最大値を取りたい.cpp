#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

/**
 * https://atcoder.jp/contests/abc134/submissions/6478504
 * lft[i] := A[0]～A[i]までの最大値
 * rht[i] := A[i]～A[N-1]までの最大値
 * これを作っておけば、i番目以外の最大値はmax(lft[i - 1], rht[i + 1])となる。
 */
int main() {
  // 入力
  int N;  // <= 2 * 10^5
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];

  // 処理
  vector<int> lft = A, rht = A;
  for (int i = 1; i < N; i++) {
    // 0 ~ iまでの最大値をlft[i]に格納する
    lft[i] = max(lft[i], lft[i - 1]);
  }
  for (int i = N - 2; i >= 0; i--) {
    // i ~ N-1までの最大値をrht[i]に格納する
    rht[i] = max(rht[i], rht[i + 1]);
  }

  for (int i = 0; i < N; i++) {
    int ans = -1;
    if (0 < i) {
      ans = max(ans, lft[i - 1]);
    }
    if (i + 1 < N) {
      ans = max(ans, rht[i + 1]);
    }
    cout << ans << endl;
  }
}