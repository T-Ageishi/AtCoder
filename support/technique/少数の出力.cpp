#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  int a, b, d;
  cin >> a >> b >> d;

  double r = hypot(a, b);      // 原点から(a,b)の距離を求める
  double theta = atan2(b, a);  // 座標から角度を求める

  theta += d * acos(-1.0) / 180.0;

  double x = cos(theta) * r;
  double y = sin(theta) * r;

  // fixedとsetprecisionをcoutに含める
  cout << fixed << setprecision(10) << x << " " << y << endl;
}