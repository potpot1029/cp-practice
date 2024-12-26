#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> idxs;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        idxs.push(make_pair(a, i));
    }
    
    int cur_idx = -1, cur_end = n;
    vector<int> ans;
    while (!idxs.empty()) {
        auto cur = idxs.top();
        idxs.pop();
        long long val = cur.first; int idx = cur.second;

        if (idx < cur_idx) {
            idxs.push(make_pair(val+1, cur_end++));
        }
        else {
            cur_idx = idx;
            ans.push_back(val);
        }
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