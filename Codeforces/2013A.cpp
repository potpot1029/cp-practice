#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n;
  cin >> n;

  int x, y;
  cin >> x >> y;
  if (x > y) swap(x, y);

  cout << (int) ceil((double) n / x) << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    solve();
  }

  return 0;
}
