#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
const ll infl = 1LL << 60;
const int inf = INT_MAX / 2;
const string yes = "Yes";
const string no = "No";

/** ------------------------------------------------------------------ */

class BipartiteGraph {
 public:
  vector<vector<int>> graph;
  vector<int> seen;
  int N, M;
  bool is_bipartite = true;

  /**
   * 初期化
   */
  BipartiteGraph(int n, int m) {
    this->N = n, this->M = m;
    this->graph.resize(N);
    this->seen.resize(N, -1);
  };

  /**
   * グラフの作成
   */
  BipartiteGraph* init(vector<int> a, vector<int> b) {
    for (int i = 0; i < M; i++) {
      this->graph[a[i]].push_back(b[i]);
      this->graph[b[i]].push_back(a[i]);
    }
    return this;
  };

  /**
   * 二部グラフ判定
   */
  bool judge() {
    for (int i = 0; i < N; i++) {
      if (this->seen[i] == -1) {
        this->_dfs(i, 0);
      }
    }
    return this->is_bipartite;
  }

  /**
   * グラフに印をつけていく
   */
  void _dfs(int pos, int color) {
    this->seen[pos] = color;

    for (auto nex : this->graph[pos]) {
      if (this->seen[nex] == -1) this->_dfs(nex, 1 - color);
      else if (this->seen[nex] == this->seen[pos]) this->is_bipartite = false;
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> a(m), b(m);
  for (int i = 0; i < m; i++) cin >> a[i], a[i]--;
  for (int i = 0; i < m; i++) cin >> b[i], b[i]--;

  BipartiteGraph bg(n, m);
  if (bg.init(a, b)->judge()) cout << yes << endl;
  else cout << no << endl;
}
