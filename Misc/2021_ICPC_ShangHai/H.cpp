#include <bits/stdc++.h>

using num = int64_t;
using namespace std;
#define rep(i, a, b) for(num i = a; i < (b); ++i)
#define REPI(t, n) for (num t = 0; t < n; ++t)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;


struct Edge {
    Edge(int u, int v, int w) : u(u), v(v), w(w) {};
    int u, v, w;
};

int n, l, id;
vector<int> a, sum, val, parent, head, tin, tout;
vector<Edge> edges;
vector<bool> ok;
vector<vector<int>> adj, up;

void dfs(int u, int p=-1) {
    if (adj[u].size() == 0)
        sum[u] += a[u];

    up[u][0] = p;
    for (int i = 1; i <= l; i++) {
        up[u][i] = up[up[u][i-1]][i-1];
    }
    for (auto v : adj[u]) {
        if (v != p) {
            dfs(v, u);
            sum[u] += sum[v];
        }
    }
    
}

void make_set(int v) {
    parent[v] = v;
}

int find_set(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find_set(parent[u]);
}

void unite_set(int u, int v, int w) {
	// parents of u and v
	u = find_set(u), v = find_set(v);
	if (u == v) return;
	parent[u] = parent[v] = id;

	// add edges
	adj[id].push_back(u);
	adj[id].push_back(v);
	val[id-n] = w;
	id++;
}


int main() {
    ios::sync_with_stdio(0);

    int m, q;
    cin >> n >> m >> q;

    a = vector<int>(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back(Edge(u, v, w));
    }

    sort(edges.begin(), edges.end(), [](const auto& lhs, const auto& rhs) {
        return lhs.w < rhs.w;
    });

    ok = vector<bool>(n, false);
    val = vector<int>(n, 0);
    adj = vector<vector<int>>(2*n+1);
    sum = vector<int>(2*n+1, 0);
    parent = vector<int>(2*n+1);
    
    
    for (int i = 0; i < 2*n+1; i++) 
        make_set(i);
    
    id = n;
    for (int i = 0; i < m; i++) {
        int u = edges[i].u, v = edges[i].v;
        unite_set(u, v, edges[i].w);
    }
    id--;

    l = ceil(log2(n));
    up.assign(2*n+1, vector<int>(l + 1));
    dfs(id, id);

    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        x--;

        int node = x;
        int ans = sum[node] + k;
        while (node != id) {
            int tmp = node;
            for (int j = l; j >= 0; --j) {
                if (val[up[node][j]-n] <= ans)
                    node = up[node][j];
            }
            if (tmp == node) break;
            ans = sum[node] + k;
        }

        
        cout << ans << "\n";
    }

    return 0;
}