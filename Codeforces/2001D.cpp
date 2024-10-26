#include "bits/stdc++.h"
using namespace std;

class Compare_min {
  public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
      if (a.first == b.first) return a.second > b.second;
      return a.first > b.first;
    }
};


class Compare_max {
  public:
    bool operator() (pair<int, int> a, pair<int, int> b) {
      if (a.first == b.first) return a.second > b.second;
      return a.first < b.first;
    }
};


void solve() {
  int n;
  cin >> n;

  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];

  vector<int> cnt(n+1, 0);
  int m = 0;
  for (int i = 0; i < n; ++i) {
    if (cnt[a[i]] == 0) {
      m++;
    }
    cnt[a[i]]++;
  }

  int idx = 1, last_pos = -1;
  priority_queue<pair<int, int>, vector<pair<int, int> >, Compare_min> cur_min;
  priority_queue<pair<int, int>, vector<pair<int, int> >, Compare_max> cur_max;
  vector<bool> appeared(n+1, false);
  vector<int> b;
  for (int i = 0; i < n; ++i) {
    // hit the right bound of an element
    if (cnt[a[i]] == 1 && !appeared[a[i]]) {
      // on even index: finding min
      while (true) {
        bool found = false;
        if (idx % 2 == 0) {
          while (!cur_min.empty()) {
            pair<int, int> cur = cur_min.top();
            cur_min.pop();

            int val = cur.first, pos = cur.second;
            
            if (pos < last_pos) continue;
            if (appeared[val]) continue;
            if (val <= a[i]) {
              b.push_back(val);
              idx++;
              last_pos = pos;
              appeared[val] = true;
              found = true;
              break;
            }
          }
        }
        // on odd index: finding max 
        else {
          while (!cur_max.empty()) {
            pair<int, int> cur = cur_max.top();
            cur_max.pop();

            int val = cur.first, pos = cur.second;
            if (pos < last_pos) continue;
            if (appeared[val]) continue;
            if (val >= a[i]) {
              b.push_back(val);
              idx++;
              last_pos = pos;
              appeared[val] = true;
              found = true;
              break;
            }
          }
        }
        if (!found || appeared[a[i]]) break;
      }

      // put a[i] in
      if (!appeared[a[i]]) {
        b.push_back(a[i]);
        appeared[a[i]] = true;
        idx++;
        last_pos = i;
      }
    }
    else {
      cur_min.push(make_pair(a[i], i));
      cur_max.push(make_pair(a[i], i));
    }
    cnt[a[i]]--;
  }

  // print answer
  assert(m == b.size());
  cout << m << "\n";
  for (int i = 0; i < m; ++i) {
    cout << b[i] << " \n"[i == m-1];
  }
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
