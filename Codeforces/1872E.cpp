#include "bits/stdc++.h"
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<long long> a(n);
  string s;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cin >> s;

  // xor_0 and xor_1
  long long xor_0 = 0, xor_1 = 0;
  vector<long long> prefix(n+1, 0);
  for (int i = 0; i < n; ++i) {
    prefix[i+1] = prefix[i] ^ a[i];
    if (s[i] == '1') xor_1 ^= a[i];
    else xor_0 ^= a[i];
  }

  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    
    if (type == 1) {
      int l, r;
      cin >> l >> r;

      long long range_xor = prefix[r] ^ prefix[l-1];
      xor_0 ^= range_xor;
      xor_1 ^= range_xor;
    }
    else {
      int g;
      cin >> g;

      cout << (g == 0 ? xor_0 : xor_1) << " ";
    }
  }
  cout << "\n";
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
