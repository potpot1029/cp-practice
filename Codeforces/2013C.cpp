#include "bits/stdc++.h"
using namespace std;

// 00 -> 000 -> 001 -> 100
// 000 x 1000x
// 10 -> 100 -> 101 -> 110
void solve() {
  int n;
  cin >> n;

  string ans = "0";
  string prev_ans = "";
  bool front = false, just_switched = false;
  vector<int> cnt(n+1, 0);
  while (true) {
    int is_substr;

    cout << "? " << ans << "\n";
    cout.flush();

    cin >> is_substr;
    if (is_substr == -1) exit(0);

    cnt[ans.size()]++;

    if (is_substr) {
      if (ans.size() == n) break;
      prev_ans = ans;
      if (front) ans = '0' + ans;
      else ans = ans + '0';
    }
    else {
      int head = (front ? 0 : ans.size() - 1);
      if (ans[head] == '1') { // end
        if (!front) ans = '0' + prev_ans;
        else ans = prev_ans + '0';
        front = !front;
        just_switched = true;
      }
      else {
        ans[head] = '1';
        if (just_switched) {
          if (ans.size() == n) break;
          prev_ans = ans;
          ans = '0' + ans;
          just_switched = false;
        }
      }
    }
  }
  cout << "! " << ans << "\n";
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
