#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n), pref(n+1), suff(n);
  for (int i = 0; i < n; i++) cin >> a[i];
  pref[0] = a[0];
  for (int i = 1; i < n; i++) pref[i] = max(pref[i-1], a[i]);
  suff[n-1] = a[n-1];
  for (int i = n-2; i >= 0; i--) suff[i] = min(suff[i+1], a[i]);

  int ans = 1;
  for (int i = 0; i < n-1; i++) {
    if (pref[i] <= suff[i+1]) ans++;
  }
  cout << ans << "\n";
  
  return 0;
}
