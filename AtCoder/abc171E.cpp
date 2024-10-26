#include "bits/stdc++.h"
using namespace std;

int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  long long xor_all = 0;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    xor_all ^= a[i];
  } 

  for (int i = 0; i < n; ++i) {
    cout << (xor_all ^ a[i]) << " \n"[i == n-1];
  }


  return 0;
}
