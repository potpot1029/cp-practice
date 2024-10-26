#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  vector<array<int, 2> > data;
  for (int i = 0; i < n; i++) {
    char c; int s;
    cin >> c >> s;

    array<int, 2> new_data = {s, c == '+' ?  1 : -1};
    data.push_back(new_data);
  }

  sort(data.begin(), data.end());
  int ps = 0, ng = 0, tp = 0, fn = 0;
  int old_tp = 0, old_fn = 0;
  // pre-processing (all -)
  for (int i = 0; i < n; i++) {
    if (data[i][1] == 1) ps++;
    else ng++;
  }

  double ans = 0;
  // update to + step-by-step
  for (int i = n-1; i >= 0; i--) {
    int cur_s = data[i][0];
    while (data[i][0] == cur_s) {
      // update 
      if (data[i][1] == 1) tp++;
      else fn++;
      i--;
    }
    i++;
   
    if (tp != old_tp) {
      ans += ((double) old_tp / max(ps, 1)) * (((double) fn - old_fn) / max(ng, 1));
      old_fn = fn;
      old_tp = tp;
    }
  }
  ans += ((double) tp / max(ps, 1)) * (((double) fn - old_fn) / max(ng, 1));
  cout << ans << "\n";

  return 0;
}
