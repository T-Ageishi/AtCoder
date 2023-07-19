#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

/**
 * グラフの情報を管理するための代表的な手法に
 * 隣接行列と隣接リストがある。
 * 
 * 単純無向グラフにおける隣接行列とは、各成分が0または1であるN * Nの行列であり、
 * 頂点u, vを結ぶ辺が存在するならばAuvとAvuは1であり、存在しないならば0。
 * 
 * 隣接リストとは、各頂点uについて、uと辺で結ばれている頂点のリストauを管理するというもの。
 * なお、uと辺で結ばれた頂点の個数、すなわちduを頂点uの次数と呼ぶ。
 * 
 * https://atcoder.jp/contests/abc276/tasks/abc276_b
*/
int main() {
  int N, M;
  cin >> N >> M;
  vector<vector<int>> a(N + 1);
  for (int i = 0; i < M; ++i) {
    int u, v;
    cin >> u >> v;
    a[u - 1].push_back(v);
    a[v - 1].push_back(u);
  }
  for (int i = 0; i < N; ++i) {
    sort(a[i].begin(), a[i].end());
    cout << a[i].size();
    for (int a: a[i]) {
      cout << " " << a;
    }
    cout << endl;
  }
}
