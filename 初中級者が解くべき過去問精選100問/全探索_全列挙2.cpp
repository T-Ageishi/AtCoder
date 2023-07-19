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

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      continue;
    }
    int cnt = 0;
    for (int j = 1; j * j <= i; j++) {
      if (i % j != 0) {
        continue;
      }
      if (j * j == i) {
        cnt++;
      } else {
        cnt += 2;
      }
    }
    if (cnt == 8) {
      ans++;
    }
  }
  cout << ans << endl;
}