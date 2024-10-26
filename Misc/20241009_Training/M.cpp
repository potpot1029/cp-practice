#include <bits/stdc++.h>
using namespace std;
map<string, bool> vis;
map<string, int> ign;
map<string, vector<string>> adj;

pair<int, int> dfs(string prefix) {
    vis[prefix] = true;
    int to_ignore = ign[prefix], num_nodes = (adj[prefix].size() == 0 ? 1 : 0);
    for (auto next_prefix : adj[prefix]) {
        if (vis[next_prefix]) continue;
        pair<int, int> res = dfs(next_prefix);
        to_ignore += res.first;
        num_nodes += res.second;
    }
    // cout << "visiting: " << prefix << " " << to_ignore << " " << num_nodes << "\n";
    if (prefix.size() != 0 && to_ignore == num_nodes) return make_pair(1, 1);
    else return make_pair(to_ignore, num_nodes);
}

void solve() {
    int n, m;
    cin >> n >> m;

    vis.clear();
    ign.clear();
    adj.clear();

    string s;
    int can_ignore = 1;
    for (int i = 0; i < n+m; i++) {
        if (i >= n) can_ignore = 0;
        cin >> s;
        string prev_prefix = "", cur_prefix = "";
        for (int j = 0; j < (int) s.size(); j++) {
            if (s[j] == '/') {
                ign[cur_prefix] = 0;
                adj[prev_prefix].push_back(cur_prefix);
                prev_prefix = cur_prefix;
            }
            cur_prefix += s[j];
        }
        adj[prev_prefix].push_back(cur_prefix);
        ign[cur_prefix] = can_ignore;
    }

    string root = "";
    cout << dfs(root).first << "\n";

}

int main(){
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}