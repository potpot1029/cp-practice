#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adj;
vector<int> depths, heavy;

int dfs(int u, int p, int depth = 0) {
    int heavy_sz = 0, total_sz = 0;
    depths[u] = depth;
    for (int v : adj[u]) {
        if (v == p) continue;
        int subtree_sz = dfs(v, u, depth + 1);
        total_sz += subtree_sz;
        if (subtree_sz > heavy_sz) {
            heavy_sz = subtree_sz;
            heavy[u] = v;
        }
    }
    return total_sz + 1;
}

int dfs2(int u, int depth = 1e9) {
    if (heavy[u] == 0 || depths[u] == depth) return u;
    return dfs2(heavy[u], depth);
}

int query1(int u) {
    cout << "d " << u << "\n";
    cout.flush();
    int res;
    cin >> res;
    return res;
}

int query2(int u) {
    cout << "s " << u << "\n";
    cout.flush();
    int res;
    cin >> res;
    return res;
}

void solve() {
    int n;
    cin >> n;
    adj.assign(n+1, vector<int>());
    depths.assign(n+1, 0);
    heavy.assign(n+1, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, -1);
    // dist(x, v) = dep_x + dep_v - 2 * dep_y 
    int depth_x = query1(1);
    int cur_node = 1;
    while (true) {
        // heavy path
        int v = dfs2(cur_node);
        int dist_cur_x = query1(v);
        int depth_y = (depth_x + depths[v] - dist_cur_x) / 2;
        int y = dfs2(cur_node, depth_y);
        if (depth_y == depth_x) {
            cout << "! " << y << "\n";
            break;
        }
        else {
            cur_node = query2(y);
        }
    }
}

int main() {
	ios::sync_with_stdio(0);
	int t=1;
	// cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}