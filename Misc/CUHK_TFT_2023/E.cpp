#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  long long ans = 0;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a.begin(), a.end());

  for (int i = 0; i < n; i++) {
    if (i == 0) {
      ans += a[i];
      continue;
    }
    if (ans * a[i] > ans + a[i]) ans *= a[i];
    else ans += a[i];
  }

  cout << ans << "\n";
  return 0;
}
