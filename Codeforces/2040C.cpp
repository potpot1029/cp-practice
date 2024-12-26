#include <bits/stdc++.h>
using namespace std;

long long cal(long long n, long long k) {
    if (k > 60) return 0;
    else return ((n >> k) & 1ll);
}

void solve() {
    long long n, k;
    cin >> n >> k;

    long long tot = 1ll << (min(n-1, 60ll));    
    if (tot < k) {
        cout << "-1\n";
        return;
    }

    k--;
    vector<long long> ans;
    long long cur = 1, idx = n-1;
    bool inc = true;
    stack<long long> wait;
    while (idx >= 0) {
        while (idx >= 0 && cal(k, idx-1)) {
            // cout << cal(k, idx-1) << " " << idx << " " << cur << "\n";
            wait.push(cur++);
            idx--;
        }
        // cout << cur << "\n";
        ans.push_back(cur++);
        inc = false;
        idx--;
    }

    while (cur <= n) {
        wait.push(cur++);
    }

    while (!wait.empty()) {
        long long cur = wait.top();
        wait.pop();
        ans.push_back(cur);
    }

    if (inc) {
        reverse(ans.begin(), ans.begin());
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