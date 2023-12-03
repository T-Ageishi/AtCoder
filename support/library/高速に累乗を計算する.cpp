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
ll Power(ll x, ll n, ll mod) {
  if (n == 0) return 1;

  if (n % 2 == 1) return (x * Power(x, n - 1, mod)) % mod;
  else return ((Power(x, n / 2, mod) % mod) * (Power(x, n / 2, mod) % mod)) % mod;
}

int main() {
  ll n, k;
  cin >> n >> k;

  ll mod = 1'000'000'007;
  if (n == 1) cout << k % mod << endl;
  else cout << (((k * (k - 1)) % mod) * (Power(k - 2, n - 2, mod) % mod)) % mod << endl;
}
