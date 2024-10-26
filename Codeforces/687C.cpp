#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<int> coins(n+1, 0);
  for (int i = 1; i <= n; ++i) cin >> coins[i];

  // x = coins[i]
  // dp[i][j][k] = first i coins, sum j, subset sum k is possible
  // dp[i][j][k] <- dp[i-1][j-x][k-x] | dp[i-1][j-x][k] | dp[i-1][j][k]
  bool dp[2][501][501] = {false};
  dp[0][0][0] = true;
  int last = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = k; j >= 0; j--) {
      for (int m = k; m >= 0; m--) {
        // don't include coin i in sum
        dp[last^1][j][m] |= dp[last][j][m];
        // don't include coin in subset sum
        if (j - coins[i] >= 0) {
          dp[last^1][j][m] |= dp[last][j-coins[i]][m];
          // else
          if (m - coins[i] >= 0) dp[last^1][j][m] |= dp[last][j-coins[i]][m-coins[i]];
        }
      }
    }
    last ^= 1;
  }

  vector<int> ans;
  for (int i = 0; i <= k; i++) {
    if (dp[last][k][i]) ans.push_back(i);
  }

  cout << ans.size() << "\n";
  for (int x : ans) {
    cout << x << " ";
  }
  cout << "\n";
}
