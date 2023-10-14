#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
typedef long long ll; // 9*10^18
typedef unsigned long long ull;
const int INF = 2147483647;
const long long LINF = 1LL << 60;

/** ---  MAIN  ------------------------------------------------------------- */
int n, x, y;
ll calc(int level, bool is_red) {
  // red と blueで再帰関数を分けると複雑になるのでひとつにまとめる
  if (level == 1) {
    return is_red ? 0 : 1;
  }
  if (is_red) {
    return calc(level - 1, true) + calc(level, false) * x;
  } else {
    return calc(level - 1, true) + calc(level - 1, false) * y;
  }
}

/**
 * main
 */
int main() {
  // 入力
  cin >> n >> x >> y;
  cout << calc(n, true) << endl;
}