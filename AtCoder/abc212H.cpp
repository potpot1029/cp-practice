#include "bits/stdc++.h"
using namespace std;

#define M (1 << 16) + 10
#define m (1 << 16)
const long long MOD = 998244353, INV2 = (MOD+1ll) >> 1;
#define XOR 0
#define AND 1
#define OR 2

long long fast_pow(long long n, long long k) {
    long long ans = 1;
    while (k) {
        if (k & 1) ans = ans * n % MOD;
        n = n * n % MOD;
        k >>= 1;
    }
    return ans;
}

long long inv(long long n) {
    return fast_pow(n, MOD-2);
}

void fwt_xor(long long *a, int n, int type) {
  if (n == 0) return;
  int middle = n / 2;
  fwt_xor(a, middle, type); fwt_xor(a + middle, middle, type);

  for (int i = 0; i < middle; i++) {
      long long a0 = a[i], a1 = a[i+middle];
      a[i] = (a0 + a1) * type % MOD;
      a[i+middle] = (a0 - a1 + MOD) * type % MOD;
  }
}


int main(void) {
  ios::sync_with_stdio(false);

  int n; long long k;
  cin >> n >> k;

  long long c[M];
  for (int i = 0; i < M; ++i) {
    c[i] = 0;
  }
  for (int i = 0; i < k; ++i) {
    long long a;
    cin >> a;
    c[a]++;
  }
  fwt_xor(c, m, 1);
  long long ans = 0;
  for (int i = 0; i < m; ++i) {
    if (c[i] == 1) c[i] = n;
    else {
      c[i] = c[i] * (fast_pow(c[i], n) - 1) % MOD * inv(c[i] - 1) % MOD;
    }
  }
  fwt_xor(c, m, INV2);
  for (int i = 1; i < m; ++i) {
    ans = (ans + c[i]) % MOD;
  }
  cout << ans << "\n";
  return 0;
}
