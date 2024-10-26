#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9+7;

int main(void) {
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;

  vector<int> coins(n);
  for (int i = 0; i < n; ++i) cin >> coins[i];

  vector<int> dp(x+1, 0);
  dp[0] = 1;
  for (int val_origin = 0; val_origin <= x; val_origin++) {
    for (int coin_idx = 0; coin_idx < n; coin_idx++) {
      int val_new = val_origin + coins[coin_idx];
      if (val_new > x) continue;
      dp[val_new] = (dp[val_new] + dp[val_origin]) % MOD;
    }
  }

  cout << dp[x] << "\n";

  return 0;
}
