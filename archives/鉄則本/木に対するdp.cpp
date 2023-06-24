#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;

/**
 * main
 */
int main() {
  // 入力
  int N;
  cin >> N;
  vector<int> A(N);
  vector<vector<int>> graph(N + 10);
  for (int i = 2; i <= N; i++) {
    cin >> A[i];
    graph[A[i]].push_back(i);
  }

  vector<int> dp(N + 10, 0);
  for (int i = N; i >= 1; i--) {
    for (int j = 0; j < (int)graph[i].size(); j++) {
      dp[i] += dp[graph[i][j]] + 1;
    }
  }

  for (int i = 1; i <= N; i++) {
    if (i >= 2) {
      cout << " ";
    }
    cout << dp[i];
  }
  cout << endl;
}