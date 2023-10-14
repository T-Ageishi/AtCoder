#include <bits/stdc++.h>
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
const ll infl = 1LL << 60;
const int inf = INT_MAX / 2;
const ll mo = 1000000007;
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
/* IROIRO ************************************************** */
// int gcd(int A, int B) {
//   while (A >= 1 && B >= 1) {
//     if (A >= B) A = A % B;
//     else B = B % A;
//   }
//   if (A == 0) return B;
//   return A;
// }
/* MEIN ************************************************** */

/**
 * https://atcoder.jp/contests/abc215/tasks/abc215_c
 */
int main() {
  int L, Q;
  cin >> L >> Q;

  set<int> st, mst;
  rep(i, 0, Q) {
    int c, x;
    cin >> c >> x;
    if (c == 1) {
      st.insert(x);
      mst.insert((-1) * x);
    } else if (c == 2) {
      auto ritr = st.lower_bound(x);
      auto litr = mst.lower_bound((-1) * x);
      if (ritr == st.end() && litr == mst.end()) cout << L << endl;
      else if (ritr == st.end()) cout << L - ((-1) * (*litr)) << endl;
      else if (litr == mst.end()) cout << *ritr << endl;
      else cout << *ritr - (-1) * (*litr) << endl;
    }
  }
}