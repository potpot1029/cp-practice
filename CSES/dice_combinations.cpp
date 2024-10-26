#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9+7;

int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  vector<int> dp(n+1, 0);
  dp[0] = 1;
  for (int i = 0; i < n; ++i) {
    for (int dice = 1; i+dice <= n && dice <= 6; ++dice) {
      dp[i+dice] = (dp[i+dice] + dp[i]) % MOD;
    }
  }

  cout << dp[n] << "\n";
  return 0;
}
