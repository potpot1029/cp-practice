#include "bits/stdc++.h"
#include <random>
using namespace std;


int main(void) {
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  vector<long long> a(n), b(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];


  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  uniform_int_distribution<long long> dist(1, 1ll << 43);
  vector<long long> hash(n+1);
  for (int i = 0; i <= n; ++i) {
    hash[i] = dist(rng);
  }

  vector<long long> prefix_hash_a(n+1, 0), prefix_hash_b(n+1, 0);
  for (int i = 1; i <= n; ++i) {
    prefix_hash_a[i] = prefix_hash_a[i-1] + hash[a[i-1]];
    prefix_hash_b[i] = prefix_hash_b[i-1] + hash[b[i-1]];
  }

  while (q--) {
    int la, ra, lb, rb;
    cin >> la >> ra >> lb >> rb;

    long long hash_a = prefix_hash_a[ra] - prefix_hash_a[la-1];
    long long hash_b = prefix_hash_b[rb] - prefix_hash_b[lb-1];

    if (hash_a == hash_b) {
      cout << "Yes\n";
    }
    else {
      cout << "No\n";
    }
  }

  return 0;
}
