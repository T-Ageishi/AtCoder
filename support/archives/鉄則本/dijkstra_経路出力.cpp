#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
// const long long INF = 1LL << 60;
const int INF = 2000000000;

/**
 * main
 */
int main() {
  // 入力
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M), C(M);
  vector<vector<pair<int, int>>> graph(N + 10);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    graph[A[i]].push_back({B[i], C[i]});
    graph[B[i]].push_back({A[i], C[i]});
  }

  // 処理
  vector<int> costs(N + 10, INF);  // 頂点kまでの最小コスト
  vector<bool> settled(N + 10, false);  // 頂点kまでの最短距離が確定しているか
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.push({0, 1});  // 頂点1をpush
  costs[1] = 0;
  while (!q.empty()) {
    int pos = q.top().second;
    q.pop();
    if (settled[pos]) continue;  // 最短距離確定済みのためcontinue

    settled[pos] = true;
    for (int i = 0; i < graph[pos].size(); i++) {
      int nex = graph[pos][i].first;
      int nex_cost = graph[pos][i].second;
      if (costs[nex] > costs[pos] + nex_cost) {
        costs[nex] = costs[pos] + nex_cost;
        q.push({costs[nex], nex});
      }
    }
  }

  // 経路を求める
  vector<int> route;
  int pos = N;
  while (true) {
    route.push_back(pos);
    if (pos == 1) {
      break;
    }
    vector<pair<int, int>> from = graph[pos];
    for (int i = 0; i < from.size(); i++) {
      int before_pos = from[i].first;
      int before_cost = from[i].second;
      if (costs[pos] == costs[before_pos] + before_cost) {
        pos = before_pos;
      }
    }
  }

  // 出力
  reverse(route.begin(), route.end());
  for (int i = 0; i < route.size(); i++) {
    cout << route[i];
    if (i < route.size() - 1) {
      cout << " ";
    } else {
      cout << endl;
    }
  }
}