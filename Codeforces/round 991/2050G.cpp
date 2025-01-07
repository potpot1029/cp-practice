#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj, dp;
vector<int> child;

void dfs(int u, int p) {
    vector<int> check, check1;
    for (int v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            child[u]++;
            check.push_back(max(dp[v][0], dp[v][1]));
            check1.push_back(max(dp[v][0], max(dp[v][1], max(dp[v][2], dp[v][3]-1))));
        }
    }
    
    sort(check.rbegin(), check.rend());
    sort(check1.rbegin(), check1.rend());
    if (check.size() >= 1) dp[u][3] = check1[0] + 1;
    dp[u][0] = child[u];
    if (check.size() >= 1) dp[u][1] = check[0] + child[u] - 1;
    if (check.size() >= 2) dp[u][2] = check[0] + check[1] + child[u] - 2;
    
    // cout << u << " " << dp[u][0] << " " << dp[u][1] << " " << dp[u][2] << "\n";
}

void solve() {
    int n;
    cin >> n;

    adj.assign(n+1, vector<int>());
    dp.assign(n+1, vector<int>(4, 0));
    child.assign(n+1, 0);

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    cout << max(dp[1][0], max(dp[1][1], max(dp[1][2], dp[1][3]))) << "\n";
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