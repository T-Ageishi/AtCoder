#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const ll infl = 1LL << 60;
const int inf = INT_MAX / 2;
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
/* MAIN ************************************************** */

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M), C(M);
  vector<vector<pair<int, int>>> graph(N);
  rep(i, 0, M) {
    cin >> A[i] >> B[i] >> C[i];
    A[i]--;
    B[i]--;
    graph[A[i]].push_back({B[i], C[i]});
    graph[B[i]].push_back({A[i], C[i]});
  }

  vector<int> cur(N, inf * 2);
  vector<bool> settled(N);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
  cur[0] = 0;
  que.push({cur[0], 0});
  while (!que.empty()) {
    // 次に確定させるべき頂点
    int pos = que.top().second;
    que.pop();

    // que の最小要素が「既に確定した地点」の場合
    if (settled[pos]) continue;

    // cur[x] の値を更新する
    settled[pos] = true;
    for (int i = 0; i < (int)graph[pos].size(); i++) {
      int nex = graph[pos][i].first;
      int cost = graph[pos][i].second;
      if (cur[nex] > cur[pos] + cost) {
        cur[nex] = cur[pos] + cost;
        que.push({cur[nex], nex});
      }
    }
  }

  for (auto c : cur) {
    if (c == inf * 2) cout << -1 << endl;
    else cout << c << endl;
  }
}