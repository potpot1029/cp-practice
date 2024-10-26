#include "bits/stdc++.h"
using namespace std;


int main(void) {
  ios::sync_with_stdio(false);

  int n, k;
  cin >> n >> k;

  vector<int> h(n);
  for (int i = 0; i < n; ++i) {
    cin >> h[i];
  }

  vector<int> prefix(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    prefix[i] = prefix[i-1] + h[i-1];
  }

  int min_sum = INT_MAX, min_idx = -1;
  for (int i = 0; i <= n-k; ++i) {
    int sum = prefix[i+k] - prefix[i];
    if (sum < min_sum) {
      min_sum = sum;
      min_idx = i+1;
    }
  }

  cout << min_idx << "\n";

  return 0;
}
