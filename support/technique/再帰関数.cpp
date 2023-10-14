#include <bits/stdc++.h>
using namespace std;

/**
 * https://drken1215.hatenablog.com/entry/2020/05/04/190252
 * N = 5, M = 3としてA = (2, 0, 1)の状態でdfs(A)が呼び出されるとする
 *
 * まずAの要素数がN(=5)かどうかをチェックする -> 違うのでスルー
 * 最初にv = 0について
 *   Aにvをpushする -> A=(2, 0, 1, 0)になる
 *   dfs(A)を再帰呼出しする
 *   Aをpopする -> A=(2, 0, 1)になる
 *
 * 次にv = 1について
 *   Aにvをpushする -> A=(2, 0, 1, 1)になる
 *   dfs(A)を再帰呼出しする
 *   Aをpopする -> A=(2, 0, 1)になる
 *
 * 最後にv = 2について
 *   Aにvをpushする -> A=(2, 0, 1, 2)になる
 *   dfs(A)を再帰呼出しする
 *   Aをpopする -> A=(2, 0, 1)になる
 */

const int M = 2;

void dfs(vector<int> &A) {
  // 終端条件 --- 10 重ループまで回したら処理して打ち切り
  if (A.size() == 10) {
    for (int i = 0; i < 10; ++i) cout << A[i];
    cout << endl;
    return;
  }

  for (int v = 0; v < M; ++v) {
    A.push_back(v);
    dfs(A);
    A.pop_back();  // これが結構ポイント
  }
}

int main() {
  vector<int> A;
  dfs(A);
}