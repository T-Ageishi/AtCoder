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
  map<int, int> A;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;
    if (A.count(a)) {
      A[a]++;
    } else {
      A[a] = 1;
    }
  }

  // 処理
  vector<pair<int, int>> A_pool;
  for (auto p : A) {
    A_pool.push_back({p.second, p.first});
  }
  sort(A_pool.begin(), A_pool.end());
  int ans = 0;
  if ((int)A_pool.size() <= K) {
    cout << ans << endl;
    return 0;
  }
  for (int i = 0; i < (int)A_pool.size() - K; i++) {
    ans += A_pool[i].first;
  }
  cout << ans << endl;
}