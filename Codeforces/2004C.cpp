#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  
  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    sort(a.rbegin(), a.rend());

    long long ans = 0, quota = 0;
    for (int i = 0; i < n; ++i) {
      if (i % 2 == 0) { // Alice
        ans += a[i];
      }
      else { // Bob
        ans -= a[i];
        quota += (a[i-1] - a[i]);
      }
    }

    // cout << "DEBUG: " << ans << "\n";
    cout << max(0ll, ans-min(quota, (long long) k)) << "\n";
  }

  return 0;
}
