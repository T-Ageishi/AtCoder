#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;

int N, M;  // 2 <= N <= 10^5

vector<ll> dijkstra(ll start, vector<vector<pair<ll, ll>>> graph) {
  vector<bool> settled(N + 10, false);
  vector<ll> costs(N + 10, LINF);
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  q.push({0, start});  // cost, place
  costs[start] = 0;
  while (!q.empty()) {
    ll pos = q.top().second;
    q.pop();
    if (settled[pos]) continue;
    settled[pos] = true;
    for (int i = 0; i < (int)graph[pos].size(); i++) {
      ll nex = graph[pos][i].first;
      ll nex_cost = graph[pos][i].second;
      if (costs[nex] > costs[pos] + nex_cost) {
        costs[nex] = costs[pos] + nex_cost;
        q.push({costs[nex], nex});
      }
    }
  }
  return costs;
}

/**
 * 少しひねったダイクストラ法
 * https://atcoder.jp/contests/abc035/submissions/42887079
 */
int main() {
  // 入力
  ll T;
  cin >> N >> M >> T;
  vector<ll> A(N + 10);
  for (int i = 1; i <= N; i++) cin >> A[i];
  vector<ll> a(M + 10), b(M + 10), c(M + 10);
  vector<vector<pair<ll, ll>>> graph(N + 10), rgraph(N + 10);
  for (int i = 1; i <= M; i++) {
    cin >> a[i] >> b[i] >> c[i];
    graph[a[i]].push_back({b[i], c[i]});
    rgraph[b[i]].push_back({a[i], c[i]});
  }

  // 処理
  vector<ll> costs = dijkstra(1, graph);
  vector<ll> rcosts = dijkstra(1, rgraph);

  ll mx = -1;
  for (int i = 1; i <= N; i++) {
    if (costs[i] == LINF || rcosts[1] == LINF) continue;
    // i番目の町に滞在し続けるとする
    ll time = T - costs[i] - rcosts[i];
    if (time < 0) continue;
    mx = max(mx, time * A[i]);
  }
  cout << mx << endl;
}