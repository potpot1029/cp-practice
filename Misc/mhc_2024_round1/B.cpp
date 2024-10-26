#include "bits/stdc++.h"
using namespace std;

void solve(int case_no) {
  long long n;
  cin >> n;

  vector<int> lp(n+1);
  vector<int> pr;

  for (int i = 2; i <= n; i++) {
    if (lp[i] == 0) {
      lp[i] = i;
      pr.push_back(i);
    }
    for (int j = 0; i * pr[j] <= n; j++) {
      lp[i * pr[j]] = pr[j];
      if (pr[j] == lp[i]) {
        break;
      }
    }
  }

  int ans = 0;
  bool two = false;
  if (pr.size()) {
    vector<int> prefix(pr.size());
    for (int i = 1; i < pr.size(); i++) {
      prefix[i] = prefix[i-1] + (pr[i] - pr[i-1]);
      if (pr[i] - pr[i-1] == 2 && !two) {
        ans++;
        two = true;
      }
      if (lp[prefix[i]] == prefix[i]) ans++;
    }
  }
  
  cout << "Case #" << case_no << ": " << ans << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }

  return 0;
}
