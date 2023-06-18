#include <bits/stdc++.h>
using namespace std;

int count = 0;

/**
 * 最大公約数を返す
 */
long long euclidean(long long A, long long B) {
  // ベースケース
  if (B == 0) {
    return A;
  }

  // 再帰ステップ
  return euclidean(B, A % B);
}

long long gcd(long long A, long long B) {
  while (A >= 1 && B >= 1) {
    if (A < B) {
      B = B % A;
    } else {
      A = A % B;
    }
  }
  if (A >= 1) {
    return A;
  }
  return B;
}

int main() {
  long long A, B, C, tmp;
  vector<long long> v;
  for (int i = 0; i < 3; i++) {
    cin >> tmp;
    v.push_back(tmp);
  }
  sort(v.begin(), v.end());
  A = v.at(2);
  B = v.at(1);
  C = v.at(0);

  // ユークリッドの互除法で3つの数の最大公約数を求める
  long long greatest_common_divisor = euclidean(A, euclidean(B, C));
  long long ans = 0;
  ans += (A / greatest_common_divisor) - 1;
  ans += (B / greatest_common_divisor) - 1;
  ans += (C / greatest_common_divisor) - 1;
  cout << ans << endl;
}
