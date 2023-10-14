#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long INF = 1LL << 60;

/**
 * main
 */
int main() {
  // 入力
  int N, K;
  cin >> N >> K;
  map<int, int> map_a;
  A[1] = 4;
  A[2] = 3;
  A[3] = 2;
  A[4] = 1;

  // mapをpairに分解する
  vector<pair<int, int>> sort_a;
  for (auto p : A) {
    // mapのkeyとvalueを逆にしたpairを作り、配列にpush
    sort_a.push_back({p.second, p.first});
  }
  // 普通にソート
  sort(sort_a.begin(), sort_a.end());
}