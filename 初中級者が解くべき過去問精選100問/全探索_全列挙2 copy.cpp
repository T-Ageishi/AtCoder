#include <bits/stdc++.h>
using namespace std;
typedef long long ll; // 9*10^18
typedef unsigned long long ull;
const long long LINF = 1LL << 60;
const int INF = 2147483647;

/**
 * main
 */
int main() {
  // 入力
  int n;
  cin >> n;
  vector<int> A(n), B(n), C(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> C[i];
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  sort(C.begin(), C.end());

  // 処理
}