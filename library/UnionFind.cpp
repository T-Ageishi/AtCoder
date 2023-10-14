#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

class UnionFind {
 public:
  vector<int> parent(100009);
  vector<int> siz(100009);

  // N頂点の Union-Findを作成
  void init(int N) {
    for (int i = 1; i <= N; i++) parent[i] = -1;  // 最初は親がない
    for (int i = 1; i <= N; i++) siz[i] = 1;      // 最初は頂点数が1
  }

  // 頂点xの根を返す関数
  int root(int x) {
    if (parent[x] == -1) return x;
    else return parent[x] = root(parent[x]);
  }

  // 要素uと要素vを統合する
  void unite(int u, int v) {
    int rootU = root(u);
    int rootV = root(v);
    if (rootU == rootV) return;  // 同じグループなら処理しない
    if (siz[rootU] < siz[rootV]) {
      parent[rootU] = rootV;
      siz[rootV] = siz[rootU] + siz[rootV];
    } else {
      parent[rootV] = rootU;
      siz[rootU] = siz[rootU] + siz[rootV];
    }
  }

  // 要素uと要素vが同一のグループかどうかを返す関数
  bool same(int u, int v) { return root(u) == root(v); }
}
