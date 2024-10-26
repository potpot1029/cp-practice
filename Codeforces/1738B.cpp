#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n, k;
  cin >> n >> k;
  vector<int> prefix(k);
  for (int i = 0; i < k; ++i) {
    cin >> prefix[i];
  }

  int cur_min;
  if (n-k == 0) cur_min = prefix[0];
  else cur_min = ceil((double) prefix[0] / (double) (n-k+1));
  bool flag = true;
  for (int i = 1; i < k; ++i) {
    int cur = prefix[i] - prefix[i-1];

    if (cur_min > cur) {
      flag = false;
      break;
    }
    else {
      cur_min = cur;
    }
  }

  cout << (flag ? "Yes" : "No") << "\n";
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
