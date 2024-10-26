#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<long long> h(n);
  for (int i = 0; i < n; ++i) cin >> h[i];

  // dp[i] = minimum possible total cost incurred before reaching stone N
  // dp[j] = min(dp[j], dp[i]+abs(h[i]-h[j]))
  // j = i + k (k=1,...,K) 
  vector<long long> dp(n, 1e9+10);
  dp[0] = 0;
  for (int i = 0; i < n-1; i++) {
    for (int jump_dist = 1; jump_dist <= k; jump_dist++) {
      int j = i + jump_dist;
      if (j < n) {
        dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
      }
    }
  }

  cout << dp[n-1] << "\n";

  return 0;
}