#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
#define rep(i, b)     for (int i = 0; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
const ll infl = 1LL << 60;
const int inf = (INT_MAX / 2) * 2;
const string yes = "Yes";
const string no = "No";

/** ------------------------------------------------------------------ */
/**
 * base進数のnを10進数に変換する
 */
ll basex_to_long(int base, string n) {
  ll result = 0;
  rep(i, n.size()) {
    result = result * base + ll(n[i] - '0');
  }
  return result;
}

/**
 * 10進数のnをbase進数に変換する
 */
string long_to_basex(int base, ll n) {
  if (n == 0) return "0";
  string result = "";
  while (n > 0) {
    result = char(n % base + '0') + result;
    n /= base;
  }
  return result;
}

/**
 * 数字並べ系
 * ・各数字を使うか使わないかを考えてみる
 * ・累積和が使えないかを考えてみる
 * 操作系
 * ・何回か操作したら元に戻らないか
 * ・偶奇に注目したら何かないか
 * ・データ構造を活用できないか（queue, stack, deque...）
 * 文字列系
 * ・先頭と後ろ両方から比較してみる
 * ・substrの使用には消極的
 * 問い合わせ系
 * ・最初に答えを計算しておけないか
 * ・各問い合わせに高速で回答できないか
 * ・差分を計算して高速で回答できないか
 * その他
 * ・同じものをまとめてみる
 * ・deque.erase(deque.begin() + left, deque.begin() + right);でdequeの[left, right)を削除。O(N)
 */
int main() {
  string n;
  int k;
  cin >> n >> k;
  // 8進数を10進数に変換->10進数を9進数に変換　を繰り返す
  rep(i, k) {
    n = long_to_basex(9, basex_to_long(8, n));
    rep(j, n.size()) if (n[j] == '8') n[j] = '5';
  }
  cout << n << endl;
}
