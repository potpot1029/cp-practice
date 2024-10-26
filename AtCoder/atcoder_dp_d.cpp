#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n, w;
  cin >> n >> w;

  vector<array<int, 2> > items(n, array<int, 2>());
  for (int i = 0; i < n; ++i) cin >> items[i][0] >> items[i][1];

  vector<long long> dp(w+1, 0);
  for (int i = 0; i < n; ++i) {
    int cur_w = items[i][0];
    long long cur_val = items[i][1];
    for (int w_origin = w-cur_w; w_origin >= 0; --w_origin) {
      dp[w_origin+cur_w] = max(dp[w_origin+cur_w], dp[w_origin] + cur_val);
    }
  }

  long long ans = 0;
  for (int i = 0; i <= w; ++i) {

    ans = max(ans, dp[i]);
  }

  cout << ans << "\n";
  return 0;
}
