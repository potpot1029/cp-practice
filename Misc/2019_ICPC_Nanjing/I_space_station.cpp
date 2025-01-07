#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9+7;
const int MAXN = 1e5+10;
vector<long long> a, cnt(51), fac(MAXN);
map<vector<long long>, long long> memo;
long long ans = 0;
int n;


void init_fac() {
    fac[0] = 1;
    for (int i = 1; i < MAXN; i++) {
        fac[i] = (fac[i] * fac[i-1]) % MOD;
    }
}

long long dfs(int energy, int remain) {
    if (remain == 0) return 1;
    if (energy >= 50) return fac[remain];
    if (memo.count(cnt)) return memo[cnt];
    long long res = 0;
    for (int i = 1; i <= energy; i++) {
        if (cnt[i] == 0) continue;
        
        int ori_cnt = cnt[i];
        cnt[i]--;
        res = (res + (ori_cnt * dfs(energy + i, remain-1)) % MOD) % MOD;
        cnt[i]++;
    }
    memo[cnt] = res;
    return memo[cnt];
}

int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    a.assign(n+1, 0);

    init_fac();

    for (int i = 0; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cnt[a[i]]++;
    ans = dfs(a[0], n);
    cout << ans << "\n";
    return 0;
}