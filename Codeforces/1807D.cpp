#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n, q;
  cin >> n >> q;

  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<long long> prefix(n+1, 0);
  for (int i = 1; i <= n; ++i) prefix[i] = prefix[i-1] + a[i-1];

  long long sum = prefix[n];

  while (q--) {
    int l, r;
    long long k;
    cin >> l >> r >> k;

    long long old_range_sum = prefix[r] - prefix[l-1];
    long long new_range_sum = k * (r - l + 1);
    long long new_sum = sum - old_range_sum + new_range_sum;
    cout << (new_sum % 2 == 0 ? "No" : "Yes") << "\n";
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
