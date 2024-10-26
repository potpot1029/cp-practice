#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<long long> ans(n, 0);
  long long cur = 1;
  long long ans_val = 0;
  for (int i = k-1; i < n; i += k) {
    ans[i] = cur++;
    ans_val += ans[i] * min(k, n-i);
  }
  for (int i = 0; i < n; i++) {
    if (ans[i] == 0) {
      ans[i] = cur++;
    }
  }

  cout << ans_val << "\n";
  for (int i = 0; i < n; i++) {
    cout << ans[i] << " \n"[i == n-1];
  }
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
