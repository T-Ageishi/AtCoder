#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
using namespace std;
typedef long long ll; // 9*10^18
typedef unsigned long long ull;
const int INF = 2147483647;
const long long LINF = 1LL << 60;

/** ---  MAIN  ------------------------------------------------------------- */

/**
 * main
 */
int main() {
  // 入力
  int h1, w1;
  cin >> h1 >> w1;
  vector<vector<int>> grid_a(h1, vector<int>(w1));
  rep(i, 0, h1) rep(j, 0, w1) cin >> grid_a[i][j];

  int h2, w2;
  cin >> h2 >> w2;
  vector<vector<int>> grid_b(h2, vector<int>(w2));
  rep(i, 0, h2) rep(j, 0, w2) cin >> grid_b[i][j];

  // 処理
  for (int i = 0; i < (1 << h1); i++) {
    for (int j = 0; j < (1 << w1); j++) {
      // 各行・各列について、削除するかどうかを決める
      vector<int> hvec, wvec;
      for (int k = 1; k <= h1; k++) {
        if ((i & (1 << (k - 1))) == 0) {
          hvec.push_back(k);
        }
      }
      for (int k = 1; k <= w1; k++) {
        if ((j & (1 << (k - 1))) == 0) {
          wvec.push_back(k);
        }
      }
      if (hvec.size() != h2 || wvec.size() != w2) {
        continue;
      }

      bool match = true;
      for (int k = 1; k <= h2; k++) {
        for (int l = 1; l <= w2; l++) {
          if (grid_a[hvec[k - 1] - 1][wvec[l - 1] - 1] !=
              grid_b[k - 1][l - 1]) {
            match = false;
            break;
          }
        }
      }
      if (match) {
        cout << "Yes" << endl;
        return 0;
      }
    }
  }
  cout << "No" << endl;
}