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
  // 「未探索」の頂点について、
  // DFS or BFSで同じ連結成分に含まれる頂点をすべて探索済みにする
  // DFS or BFSを行った回数が連結成分の個数
  vector<bool> visited(N + 10, false);
  vector<int> vertices;
  for (int v = 1; v <= N; v++) {
    if (visited[v]) {
      continue;
    }
    // 頂点vから行けるところを探索
    set<int> vset;
    queue<int> q;
    q.push(v);
    while (!q.empty()) {
      int pos = q.front();
      q.pop();
      vset.insert(pos);
      for (int i = 0; i < (int)graph[pos].size(); i++) {
        if (!visited[graph[pos][i]]) {
          q.push(graph[pos][i]);
          visited[graph[pos][i]] = true;
        }
      }
    }
    vertices.push_back((int)vset.size());
  }
  int mx = 0;
  for (auto v : vertices) {
    mx += v - 1;
  }
  cout << M - mx << endl;
}