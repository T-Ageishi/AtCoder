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

struct Edge {
  int to;   // 辺の行先
  int cap;  // 辺の容量
  int rev;  // 逆辺がgraph[graph[u][i].to]の何番目に存在するか
};

/**
 * 最大フロー問題
 */
class MaximumFlow {
 public:
  int size_ = 0;
  vector<bool> used;
  vector<vector<Edge>> graph;

  MaximumFlow() {
    used.resize(409);
    graph.resize(409);
  }

  /**
   * 頂点数nの残余グラフを準備
   */
  void init(int n) {
    size_ = n;
    for (int i = 0; i <= size_; i++) graph[i].clear();
  }

  /**
   * 頂点aからbに向かう、上限cリットル/秒の辺を追加
   */
  void add_edge(int a, int b, int c) {
    int current_ga = graph[a].size();
    int current_gb = graph[b].size();
    graph[a].push_back(Edge{b, c, current_gb});
    graph[b].push_back(Edge{a, 0, current_ga});
  }
};
