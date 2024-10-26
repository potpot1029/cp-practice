#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  vector<long long> x(n), pref(n+1, 0);
  for (int i = 0; i < n; ++i) cin >> x[i];
  for (int i = 1; i <= n; ++i) {
    pref[i] = pref[i-1] ^ x[i-1];
  }

  while (q--) {
    int a, b;
    cin >> a >> b;
    cout << (pref[a-1] ^ pref[b]) << "\n";
  }
  return 0;
}
