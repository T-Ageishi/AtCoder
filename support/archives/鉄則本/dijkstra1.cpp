#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
// const long long INF = 1LL << 60;
const int INF = 2000000000;

/**
 * https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_bl
 */
int main() {
  // 入力
  int N, M;
  cin >> N >> M;
  vector<int> A(M + 10), B(M + 10), C(M + 10);
  vector<vector<pair<int, int>>> graph(N + 10);
  for (int i = 0; i < M; i++) {
    cin >> A[i] >> B[i] >> C[i];
    graph[A[i]].push_back({B[i], C[i]});
    graph[B[i]].push_back({A[i], C[i]});
  }

  // 処理
  vector<int> dist(N + 10, INF);  // 頂点1から頂点k(1<=k<=N)への最短経路
  vector<bool> settled(N + 10, false);  // その点までの最短距離が確定しているか
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      q;
  q.push({0, 1});  // firstがコスト、secondが地点を表すid
  dist[1] = 0;
  while (!q.empty()) {
    // 未確定の地点の中から最も小さい値をもつ地点を1つ選び、その値を確定させる
    int pos = q.top().second;
    q.pop();
    if (settled[pos]) continue;

    settled[pos] = true;
    // posと直接つながっていて、未確定の地点に対してコストを計算し、
    // そのコストが現在想定されているコストより小さければ更新
    for (int i = 0; i < graph[pos].size(); i++) {
      int nex = graph[pos][i].first;
      int cost = graph[pos][i].second;
      if (dist[nex] > dist[pos] + cost) {
        dist[nex] = dist[pos] + cost;
        q.push({dist[nex], nex});
      }
    }
  }

  // 出力
  for (int i = 1; i <= N; i++) {
    if (dist[i] == INF) {
      cout << "-1" << endl;
    } else {
      cout << dist[i] << endl;
    }
  }
}