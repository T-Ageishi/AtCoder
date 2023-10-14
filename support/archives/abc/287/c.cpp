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
  int N, M;
  cin >> N >> M;
  vector<vector<int>> graph(N + 10);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    graph[a].push_back(b);
    graph[b].push_back(a);
  }

  // 処理
  bool ans = true;
  vector<bool> visited(N + 10, false);
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while (!q.empty()) {
    int pos = q.front();
    q.pop();
    for (int i = 0; i < (int)graph[pos].size(); i++) {
      int next = graph[pos][i];
      if (visited[next]) {
        continue;
      }
      if (i > 1) {
        ans = false;
      }
      q.push(next);
      visited[next] = true;
    }
  }
  if (!ans) {
    cout << "No" << endl;
  } else {
    for (int i = 1; i <= N; i++) {
      if (!visited[i]) {
        cout << "No" << endl;
        return 0;
      }
    }
    if (M == N - 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}