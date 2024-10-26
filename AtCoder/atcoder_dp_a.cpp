#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<long long> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  // dp[i] = minimum possible total cost incurred before reaching stone N
  // dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]))
  // j = i + 1 pr i + 2
  vector<long long> dp(n, 1e9+10);
  dp[0] = 0;
  for (int i = 0; i < n-1; i++) {
    if (i+1 < n) dp[i+1] = min(dp[i+1], dp[i] + abs(h[i] - h[i+1]));
    if (i+2 < n) dp[i+2] = min(dp[i+2], dp[i] + abs(h[i] - h[i+2]));
  }

  cout << dp[n-1] << "\n";

  return 0;
}
