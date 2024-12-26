#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
    } 
    for (int i = 0; i < n; i++) {
        cin >> a[i].second;
    }

    vector<int> remains;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans += max(a[i].first, a[i].second);
        remains.push_back(min(a[i].first, a[i].second));
    }
    sort(remains.rbegin(), remains.rend());
    ans += remains[0];
    cout << ans << "\n";
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