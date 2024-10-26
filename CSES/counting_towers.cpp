#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9+7;

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  // dp[i] = number of towers of height n
  // dp[i][1] = last row are from the same block
  // dp[i][2] = last row are from different block
  vector<vector<long long> > dp(1e6+1, vector<long long>(3, 0));

  dp[1][1] = dp[1][2] = 1;
  for (int height = 2; height <= 1e6; height++) {
    dp[height][1] = (dp[height-1][1] * 2) % MOD;
    dp[height][1] = (dp[height][1] + dp[height-1][2]) % MOD;
    dp[height][2] = (dp[height-1][2] * 4) % MOD;
    dp[height][2] = (dp[height][2] + dp[height-1][1]) % MOD;
  }


  while (t--) {
    int n;
    cin >> n;
    cout << (dp[n][2] + dp[n][1]) % MOD << "\n";
  }

  return 0;
}
