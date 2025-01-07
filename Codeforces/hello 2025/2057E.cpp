#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;


struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

struct Edge {
    int node1, node2, w;
};

bool cmp(const Edge &a, const Edge &b) {
    return a.w < b.w;
}

void solve() {
    int n, m, q;
    cin >> n >> m >> q;

    vector<Edge> edges;
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back((Edge){u, v, w});
    }
    sort(edges.begin(), edges.end(), cmp);


    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(n+1, vector<int>(n+1, INF)));
    for (int i = 0; i < m; i++) {
        int node1 = edges[i].node1, node2 = edges[i].node2;
        dp[0][node1][node2] = dp[0][node2][node1] = 1;
    }
    for (int i = 1; i <= n; i++) {
        dp[0][i][i] = 0;
    }
    for (int x = 1; x <= n; x++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) { 
                dp[0][i][j] = min(dp[0][i][j], dp[0][i][x] + dp[0][x][j]);
            }
        }
    }
    vector<int> ans(n, 0);
    UF dsu(n+1);
    for (int idx = 0, k=1; idx < edges.size(); idx++) {
        int node1 = edges[idx].node1, node2 = edges[idx].node2, w = edges[idx].w;
        if (dsu.sameSet(node1, node2)) continue;
        dsu.join(node1, node2);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dp[k][i][j] = min({dp[k-1][i][j], dp[k-1][node1][i] + dp[k-1][node2][j], dp[k-1][node2][i] + dp[k-1][node1][j]});
                // cout << k << " " << i << " " << j << " " << dp[k][i][j] << "\n"; 
            }
            
        }
        ans[k++] = w;
    }
    while (q--) {
        int a, b, k;
        cin >> a >> b >> k;

        int l = 0, r = n-1;
        while (l < r - 1) {
            int mid = (l + r) / 2;
            // cout << l << " " << r << "\n";
            if (dp[mid][a][b] < k) {
                r = mid;
            }
            else {
                l = mid;
            }
        }
        cout << ans[r] << " ";
    }
    cout << "\n";
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