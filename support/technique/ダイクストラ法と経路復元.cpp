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
  vector<vector<pair<int, int>>> graph(N);
  rep(i, 0, M) {
    int a, b, c;
    cin >> a >> b >> c;
    a--;
    b--;
    graph[a].push_back({b, c});
    graph[b].push_back({a, c});
  }

  vector<bool> settled(N);
  vector<int> cur(N, inf * 2);
  priority_queue<pair<int, int>, vector<pair<int, int>>,
                 greater<pair<int, int>>>
      que;
  cur[0] = 0;
  que.push({cur[0], 0});  // 暫定距離, 頂点番号
  while (!que.empty()) {
    int pos = que.top().second;
    que.pop();

    if (settled[pos]) continue;

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

  vector<int> path;
  path.push_back(N - 1);
  while (true) {
    int pos = path.back();
    for (int i = 0; i < (int)graph[pos].size(); i++) {
      if (cur[graph[pos][i].first] + graph[pos][i].second == cur[pos]) {
        path.push_back(graph[pos][i].first);
        break;
      }
    }
    if (pos == 0) break;
  }
  reverse(path.begin(), path.end());
  for (int i = 0; i < (int)path.size(); i++) {
    if (i > 0) cout << " ";
    cout << path[i] + 1;
  }
  cout << endl;

  return 0;
}