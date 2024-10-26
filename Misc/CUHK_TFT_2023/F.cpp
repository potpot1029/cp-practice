#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n;
  string s;
  cin >> n >> s;

  // dp[n][n] = solution where last split is at n and n splits
  // dp[i][j] <- (split/not split) max(dp[0..i-1][j-1], dp[0..i-1][j])
  vector<vector<long long> > dp(n+1, vector<long long>(n+1, 0));
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j+i <= n; j++) { // last split position
      for (int k = j+1; k < j+i; k++) {
        long long lenx = k-j, leny = j+i-k, diff = abs(s[k] - s[k-1]);
        dp[j][j+i] = max(dp[j][j+i], dp[j][k] + dp[k][j+i] + lenx * leny * diff);
        // cout << "ijk: " << i << " " << j << " " << k << " " << dp[i][j+i] << "\n";
      }
    }
  }
  
  cout << dp[0][n] << "\n";
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
