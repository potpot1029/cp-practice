#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n, x;
  cin >> n >> x;

  vector<int> prices(n), pages(n);
  for (int i = 0; i < n; i++) cin >> prices[i];
  for (int i = 0; i < n; i++) cin >> pages[i];

  vector<int> dp(x+1, -1);
  dp[0] = 0;
  for (int book_idx = 0; book_idx < n; book_idx++) {
    for (int money = x-prices[book_idx]; money >= 0; money--) {
      int money_remain = money + prices[book_idx];
      dp[money_remain] = max(dp[money_remain], dp[money] + pages[book_idx]);
    }
  }

  int ans = 0;
  for (int i = 0; i <= x; i++) {
    ans = max(ans, dp[i]);
  }
  cout << ans << "\n";

  return 0;
}
