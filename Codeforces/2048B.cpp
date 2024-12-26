#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;

    vector<int> ans(n, 0);
    int  ptr = 1;
    for (int i = k-1; i < n; i += k) {
        ans[i] = ptr++;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) ans[i] = ptr++;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i == n-1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}