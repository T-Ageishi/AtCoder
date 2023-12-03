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
  vec.erase(unique(all(vec), vec.end()));
};
template <typename T>  // sort->reverse
void sorev(vector<T> &vec) {
  sort(all(vec));
  reverse(all(vec));
};

/** ------------------------------------------------------------------ */
vector<PLL> prime_factorize(ll N) {
  vector<PLL> res;
  for (ll a = 2; a * a <= N; a++) {
    if (N % a != 0) continue;
    ll ex = 0;  // 指数

    // 割れる限り割り続ける
    while (N % a == 0) {
      ex++;
      N /= a;
    }
    res.push_back(make_pair(a, ex));
  }
  if (N != 1) res.push_back(make_pair(N, 1));
  return res;
}
int main() {
  ll n;
  cin >> n;
  vector<PLL> pll = prime_factorize(n);
}
