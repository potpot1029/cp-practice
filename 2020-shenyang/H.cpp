#include "bits/stdc++.h"
using namespace std;

struct card {
  int d, k, c;
};

struct record {
  int p, q;
};

int main(void) {
  ios::sync_with_stdio(false);
  
  int n, m, r;
  cin >> n >> m >> r;

  vector<card> discnts(n);
  vector<record> rent(m);
  for (int i = 0; i < n; i++) {
    cin >> discnts[i].d >> discnts[i].k >> discnts[i].c;
  }
  for (int i = 0; i < m; i++) {
    cin >> rent[i].p >> rent[i].q;
  }
  
  return 0;
}
