#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;

struct UnionFind {
  /**
   * 頂点iの親を管理する
   * 自分自身が根のとき-1
   */
  vector<int> p;

  UnionFind(int n) { p.resize(n, -1); }

  /**
   * 頂点xの親を見つける
   */
  int find(int x) {
    if (p[x] == -1) {
      return x;
    } else {
      return p[x] = find(p[x]);
    }
  }

  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return;
    p[x] = y;
  }

  /**
   * 頂点xと頂点yが同じ集合に属するか調べる
   */
  bool same(int x, int y) { return find(x) == find(y); }
};

/**
 * main
 */
int main() {
  // 入力
  int N, Q;
  cin >> N >> Q;
  UnionFind uf(N);
  for (int i = 0; i < Q; i++) {
    int type, u, v;
    cin >> type >> u >> v;
    if (type == 1) {
      uf.unite(u, v);
    } else {
      bool isSame = uf.same(u, v);
      if (isSame) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
}