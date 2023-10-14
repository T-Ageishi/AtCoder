#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int N;
  cin >> N;
  vector<int> v;
  rep(i, N) v.push_back(i + 1);
  do {
    // ここに処理を書く
    // vは1~Nの順列
  } while (next_permutation(v.begin(), v.end()));
  int ans = abs(a - b);
  cout << ans << endl;
}