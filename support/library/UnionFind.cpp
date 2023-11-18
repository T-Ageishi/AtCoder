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

class UnionFind {
 public:
  vector<int> par;
  vector<int> siz;

  UnionFind() {
    par.resize(100'009);
    siz.resize(100'009);
  }

  /**
   * n頂点のUnion-Findを作成
   */
  void init(int n) {
    for (int i = 0; i < n; i++) par[i] = -1;  // 最初は親がない
    for (int i = 0; i < n; i++) siz[i] = 1;
  }

  /**
   * 頂点xの根を返す
   */
  int root(int x) {
    if (par[x] == -1) return x;  // 1つ先がないのでxが根
    return root(par[x]);
  }

  /**
   * 要素uと要素vを統合する
   */
  void unite(int u, int v) {
    int rootU = root(u);
    int rootV = root(v);
    if (rootU == rootV) return;  // 既に同じグループ

    if (siz[rootU] < siz[rootV]) {
      par[rootU] = rootV;
      siz[rootV] = siz[rootU] + siz[rootV];
    } else {
      par[rootV] = rootU;
      siz[rootU] = siz[rootU] + siz[rootV];
    }
  }

  /**
   * 要素uと要素vが同じグループかどうかを返す
   */
  bool same(int u, int v) {
    return root(u) == root(v);
  }
};
