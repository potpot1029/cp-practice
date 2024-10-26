#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  long long ans = 0;
  for (int i = 0; i < n-2; i++) ans -= a[i];
  ans += a[n-2];
  ans = a[n-1] - ans;
  cout << ans << "\n";
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
