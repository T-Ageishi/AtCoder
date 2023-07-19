#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (n); i++)

int main() {
  string S;
  cin >> S;

  // 小文字から大文字への変換
  string ans = "";
  for (int i = 0; i < S.size(); i++) {
    ans += toupper(S.at(i));
  }

  // 大文字から小文字への変換
	ans = "";
	for (int i = 0; i < S.size(); i++) {
		ans += tolower(S.at(i));
	}
  //小文字であることを確認するには
  //a ~ zの間に対象の文字があることを確認したらよい
  //if ('a' <= S[i] and S[i] <= 'z'
}
