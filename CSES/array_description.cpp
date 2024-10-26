#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9+7;

int main(void) {
  ios::sync_with_stdio(false);

  int n, m;
  cin >> n >> m;
  vector<int> x(n);
  for (int i = 0; i < n; i++) cin >> x[i];

  vector<vector<int> > dp(n, vector<int>(m+1, 0));
  for (int idx = 0; idx < n; idx++) {
    for (int x_cnd = 1; x_cnd <= m; x_cnd++) {
      if (x[idx] != 0 && x_cnd != x[idx]) continue;
      if (idx == 0) {
        dp[idx][x_cnd] = (dp[idx][x_cnd] + 1) % MOD;
        continue;
      }
      for (int offset = -1; offset <= 1; offset++) {
        int adj = x_cnd + offset;
        if (adj >= 1 && adj <= m) {
          dp[idx][x_cnd] = (dp[idx][x_cnd] + dp[idx-1][adj]) % MOD;
        }
      }
    }
  }

  int ans = 0;
  for (int i = 1; i <= m; i++) {
    ans = (ans + dp[n-1][i]) % MOD;
  }
  cout << ans << "\n";

  return 0;
}
