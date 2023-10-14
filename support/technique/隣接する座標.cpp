#include <bits/stdc++.h>
using namespace std;

/**
 * N * Nのグリッドで上下左右がつながっているとき
 * 元の移動先をpointとして、移動先を修正して返す
*/
int convert(int point) {
  int N;
  if (point < 0) {
    return N - 1;
  } else if (point > N - 1) {
    return 0;
  }
  return point;
}

/**
 * 隣接する座標にアクセスする
 * 例題：https://atcoder.jp/contests/abc075/tasks/abc075_b
 */
int main() {
  int h, w;
  cin >> h >> w;

  string board[50];
  for (int i = 0; i < h; i++) cin >> board[i];

  // (x,y)近傍の座標(xx, yy)はxx = x + dx, yy = y + dy
  // 上下で(dx, dy)のペアを作る
  const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
  const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if (board[i][j] == '#') continue;

      int num = 0;
      for (int d = 0; d < 8; d++) {
        // 周囲の座標を作る
        const int di = i + dy[d];
        const int dj = j + dx[d];

        if (di < 0 || h <= di) continue;
        if (dj < 0 || w <= dj) continue;
        if (board[di][dj] == '#') num++;
      }

      board[i][j] = char(num + '0');
    }
  }

  for (int i = 0; i < h; i++) cout << board[i] << endl;
}