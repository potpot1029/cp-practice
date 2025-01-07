#include<bits/stdc++.h>
using namespace std;
int ans = INT_MAX;

void brute_force(long long a, long long b, int cnt) {
    // cout << a << " " << b << " " << cnt << "\n";
    if (cnt > ans || cnt > 26) return;
    if (a > b) swap(a, b);
    if (a == 0) {
        if (b != 0) cnt++;
        ans = min(ans, cnt); 
        return;
    }

    long long gcd = __gcd(a, b);
    brute_force(a-gcd, b, cnt+1);
    brute_force(a, b-gcd, cnt+1);
    
}

void solve() {
    long long a, b;
    cin >> a >> b;
    ans = INT_MAX;
    brute_force(a, b, 0);
    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int T=1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
