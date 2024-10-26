#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; ++i) cin >> coins[i];

  // dp[i] = minimum number of coins to produce i
  // dp[j] = min(dp[j], dp[i]+1)
  // j = i + coin
  vector<int> dp(x+1, 1e7);
  dp[0] = 0;
  for (int val_origin = 0; val_origin <= x; val_origin++) {
    for (int coin_idx = 0; coin_idx < n; coin_idx++) {
      int val_new = val_origin + coins[coin_idx];
      if (val_new > x) continue;
      dp[val_new] = min(dp[val_new], dp[val_origin] + 1);
    }
  }

  cout << (dp[x] == 1e7 ? -1 : dp[x]) << "\n";

  return 0;
}