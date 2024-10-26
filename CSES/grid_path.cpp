#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9+7;

int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<string> mp(n);
  vector<vector<long long> > dp(n, vector<long long>(n, 0));
  for (int i = 0; i < n; ++i) {
    cin >> mp[i];
  }

  // dp[i][j] = number of paths to (i, j)
  dp[0][0] = (mp[0][0] == '.' ? 1 : 0);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i + 1 < n && mp[i+1][j] != '*') dp[i+1][j] = (dp[i+1][j] + dp[i][j]) % MOD;
      if (j + 1 < n && mp[i][j+1] != '*') dp[i][j+1] = (dp[i][j+1] + dp[i][j]) % MOD;
    }
  }

  cout << dp[n-1][n-1] << "\n";

  return 0;
}
