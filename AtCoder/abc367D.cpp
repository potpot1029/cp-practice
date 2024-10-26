#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n; long long m;
  cin >> n >> m;

  vector<long long> a(n, 0);
  long long sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }

  long long ans = 0, prefix = 0;
  vector<long long> remainder_cnt(m, 0);
  for (int i = 0; i < 2 * n; ++i) {
    if (i >= n) {
      remainder_cnt[(prefix-sum)%m]--;
      ans += remainder_cnt[prefix%m];
    } 
    remainder_cnt[prefix%m]++;
    prefix += a[i%n];
  }

  cout << ans << "\n";
  return 0;
}
