#include "bits/stdc++.h"
using namespace std;

int find_mex(set<int> s) {
  if (s.size() == 0) return 0;
  int cur = 0;
  for (auto x : s) {
    if (cur != x)
      return x;
    cur++;
  }
  return cur;
}

int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  vector<int> grundy(1e5+1, 1);
  grundy[1] = 0;
  for (int i = 2; i <= 1e5; i++) {
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        grundy[i] = max(grundy[i], grundy[j] + 1);
        grundy[i] = max(grundy[i], grundy[i/j] + 1);
      }
    }
  }

  int xor_sum = 0;
  for (int i = 0; i < n; i++) {
    xor_sum ^= grundy[a[i]];
  }

  cout << (xor_sum == 0 ? "Bruno" : "Anna") << "\n";
  return 0;
}
