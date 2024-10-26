#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) cin >> a[i];

  sort(a.rbegin(), a.rend());

  long long ans = 0;
  for (int i = 0; i < k; i++) {
    ans += a[i];
  }

  cout << ans << "\n";
  return 0;
}
