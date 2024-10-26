#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;

    if (lb > ra || la > rb) {
      cout << 1;
    }
    else {
      cout << min(ra, rb) - max(la, lb) + (la != lb) + (ra != rb);
    }
    cout << "\n";
  }

  return 0;
}
