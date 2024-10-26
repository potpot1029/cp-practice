#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n > 2) {
        cout << "NO\n";
    }
    else {
        if (a[1] - a[0] == 1) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
        }
    }
  }

  return 0;
}
