#include <bits/stdc++.h>
using namespace std;

/**
 * 降順ソート
 * https://atcoder.jp/contests/abc088/tasks/abc088_b
 */
int main() {
    int N;
    cin >> N;
    vector<int> v(N);

    // 入力を受け取る
    for (int i = 0; i < N; i++) cin >> v.at(i);

    // 降順ソートする
    // sortでgreater()を比較関数として渡すと降順ソートができる。
    sort(v.begin(), v.end(), greater<int>());

	// もしくは
    // sort(vec.begin(), vec.end())
    // 配列変数vecを昇順ソートする

    // reverse(vec.begin(), vec.end())
    // 配列変数vecの要素の並びを逆にする
}
