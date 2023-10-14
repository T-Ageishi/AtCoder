#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;  // 9*10^18
#define rep(i, a, b)  for (int i = a; i < b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
const ll infl = 1LL << 60;
const int inf = INT_MAX / 2;

int gcd(int A, int B) {
  while (A >= 1 && B >= 1) {
    if (A >= B) A = A % B;
    else B = B % A;
  }
  if (A == 0) return B;
  return A;
}