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
  int N, M;
  cin >> N >> M;
  vector<int> A(M + 10), B(M + 10);
  for (int i = 1; i <= M; i++) {
    // i本目の路線はA[i]とB[i]を結ぶ
    cin >> A[i] >> B[i];
  }
  int Q;
  cin >> Q;
  vector<int> queryType(Q + 10), U(Q + 10, 0), V(Q + 10, 0), x_pool(Q + 10);
  vector<bool> X(M + 10, false);  // その路線が運休になっているか
  for (int i = 1; i <= Q; i++) {
    cin >> queryType[i];  // i番目のクエリのタイプ
    if (queryType[i] == 1) {
      int x;
      cin >> x;
      X[x] = true;
      x_pool[i] = x;
    } else {
      cin >> U[i] >> V[i];
    }
  }

  // UnionFind木の準備
  UnionFind uf(N);
  for (int i = 1; i <= M; i++) {
    if (X[i]) {
      // i本目の路線が運休
      continue;
    }
    uf.unite(A[i], B[i]);
  }

  // 処理
  vector<string> Answer;
  for (int i = Q; i >= 1; i--) {
    // クエリを逆から処理
    if (queryType[i] == 1) {
      // 開通と考える
      // UnionFindは破壊は難しい
      uf.unite(A[x_pool[i]], B[x_pool[i]]);
    } else {
      bool isSame = uf.same(U[i], V[i]);
      if (isSame) {
        Answer.push_back("Yes");
      } else {
        Answer.push_back("No");
      }
    }
  }
  reverse(Answer.begin(), Answer.end());
  for (int i = 0; i < (int)Answer.size(); i++) {
    cout << Answer[i] << endl;
  }
}