#include <bits/stdc++.h>
using namespace std;

/**
 * vectorの重複排除
*/
int main() {
  vevtor<int> vec(1000);
  sort(vec.begin(), vec.end());
  vec.erase(unique(vec.begin(), vec.end()), vec.end());
}
