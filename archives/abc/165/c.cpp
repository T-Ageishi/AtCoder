#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const long long LINF = 1LL << 60;
const int INF = 2000000000;
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i > b; i--)
/* MAIN ************************************************** */

// 入力
int N, M, Q;
vector<long long> a, b, c, d;

ll score(const vector<int> &A) {
  ll res = 0;
  for (int i = 0; i < Q; ++i) {
    if (A[b[i]] - A[a[i]] == c[i]) res += d[i];
  }
  return res;
}

ll dfs(vector<int> &A) {
  if (A.size() == N) return score(A);
  ll res = 0;
  int prev_last = (A.empty() ? 0 : A.back());
  for (int add = prev_last; add < M; ++add) {
    A.push_back(add);
    res = max(res, dfs(A));
    A.pop_back();
  }
  return res;
}

/**
 * std::stable_sort
 * ランレングス圧縮
 * https://atcoder.jp/contests/abc258/tasks/abc258_a/editorial
 */
int main() {
  // 入力
  cin >> N >> M >> Q;
  a.resize(Q), b.resize(Q), c.resize(Q), d.resize(Q);
  for (int q = 0; q < Q; ++q) {
    cin >> a[q] >> b[q] >> c[q] >> d[q];
    --a[q];
    --b[q];
  }
  vector<int> A;
  cout << dfs(A) << endl;
}