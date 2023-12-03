#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef long long ll;  // 9*10^18
typedef unsigned long long ull;
typedef vector<int> VI;
typedef vector<ll> VLL;
typedef vector<char> VC;
typedef vector<string> VS;
typedef vector<bool> VB;
typedef vector<vector<int>> GI;
typedef pair<int, int> PINT;
typedef pair<ll, ll> PLL;
// マクロ
#define rep(i, b)     for (int i = 0; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define all(a)        (a).begin(), (a).end()
// 変数・定数
const ll infl = 1LL << 60;
const int inf = (INT_MAX / 2) * 2;
const string yes = "Yes";
const string no = "No";
VI alphabet(26);  // alphabet[char - 'a'] でOK.
// 関数
template <typename T>  // ユニークにする
void buniq(vector<T> &vec) {
  sort(all(vec));
  vec.erase(unique(all(vec)), vec.end());
};
template <typename T>  // sort->reverse
void sorev(vector<T> &vec) {
  sort(all(vec));
  reverse(all(vec));
};

int n, m;
ll k, ans = infl;
vector<vector<pair<int, ll>>> graph;
vector<tuple<int, int, ll>> edges;
struct UnionFind {
  vector<int> par, rank, siz;

  // 構造体の初期化
  UnionFind(int n)
      : par(n, -1), rank(n, 0), siz(n, 1) {
  }

  // 根を求める
  int root(int x) {
    if (par[x] == -1) return x;         // x が根の場合は x を返す
    else return par[x] = root(par[x]);  // 経路圧縮
  }

  // x と y が同じグループに属するか (= 根が一致するか)
  bool issame(int x, int y) {
    return root(x) == root(y);
  }

  // x を含むグループと y を含むグループを併合する
  bool unite(int x, int y) {
    int rx = root(x), ry = root(y);  // x 側と y 側の根を取得する
    if (rx == ry) return false;      // すでに同じグループのときは何もしない
    // union by rank
    if (rank[rx] < rank[ry]) swap(rx, ry);  // ry 側の rank が小さくなるようにする
    par[ry] = rx;                           // ry を rx の子とする
    if (rank[rx] == rank[ry]) rank[rx]++;   // rx 側の rank を調整する
    siz[rx] += siz[ry];                     // rx 側の siz を調整する
    return true;
  }

  // x を含む根付き木のサイズを求める
  int size(int x) {
    return siz[root(x)];
  }
};
struct Edge {
  int a, b;
  ll w;
  Edge(int a, int b, ll w)
      : a(a), b(b), w(w) {
  }
};
void main2() {
  cin >> n >> m >> k;
  vector<Edge> es;
  rep(i, m) {
    int u, v;
    ll w;
    cin >> u >> v >> w;
    --u;
    --v;
    es.emplace_back(u, v, w);
  }
  ll ans = infl;
  auto dfs = [&](auto dfs, int i, vector<int> is) -> void {
    if (is.size() == n - 1) {
      UnionFind uf = UnionFind(n);
      bool ok = true;
      ll now = 0;
      for (int ei : is) {
        auto e = es[ei];
        if (uf.issame(e.a, e.b)) ok = false;
        uf.unite(e.a, e.b);
        now = (now + e.w) % k;
      }
      if (ok) ans = min(ans, now);
      return;
    }
    if (i == m) return;

    dfs(dfs, i + 1, is);  // 選ばないとき
    is.push_back(i);
    dfs(dfs, i + 1, is);  // 選んだとき
  };
  dfs(dfs, 0, {});
  cout << ans << endl;
}

/**
 * https://drken1215.hatenablog.com/entry/2020/05/04/190252
 * N = 5, M = 3としてA = (2, 0, 1)の状態でdfs(A)が呼び出されるとする
 *
 * まずAの要素数がN(=5)かどうかをチェックする -> 違うのでスルー
 * 最初にv = 0について
 *   Aにvをpushする -> A=(2, 0, 1, 0)になる
 *   dfs(A)を再帰呼出しする
 *   Aをpopする -> A=(2, 0, 1)になる
 *
 * 次にv = 1について
 *   Aにvをpushする -> A=(2, 0, 1, 1)になる
 *   dfs(A)を再帰呼出しする
 *   Aをpopする -> A=(2, 0, 1)になる
 *
 * 最後にv = 2について
 *   Aにvをpushする -> A=(2, 0, 1, 2)になる
 *   dfs(A)を再帰呼出しする
 *   Aをpopする -> A=(2, 0, 1)になる
 */

const int M = 2;

void dfs(vector<int> &A) {
  // 終端条件 --- 10 重ループまで回したら処理して打ち切り
  if (A.size() == 10) {
    for (int i = 0; i < 10; ++i) cout << A[i];
    cout << endl;
    return;
  }

  for (int v = 0; v < M; ++v) {
    A.push_back(v);
    dfs(A);
    A.pop_back();  // これが結構ポイント
  }
}
int main() {
  vector<int> A;
  dfs(A);
}