#include<bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Dinic {
	struct Edge {
		int to, rev;
		ll c, oc;
		ll flow() { return max(oc - c, 0LL); } // if you need flows
	};
	vi lvl, ptr, q;
	vector<vector<Edge>> adj;
	Dinic(int n) : lvl(n), ptr(n), q(n), adj(n) {}
	void addEdge(int a, int b, ll c, ll rcap = 0) {
		adj[a].push_back({b, sz(adj[b]), c, c});
		adj[b].push_back({a, sz(adj[a]) - 1, rcap, rcap});
	}
	ll dfs(int v, int t, ll f) {
		if (v == t || !f) return f;
		for (int& i = ptr[v]; i < sz(adj[v]); i++) {
			Edge& e = adj[v][i];
			if (lvl[e.to] == lvl[v] + 1)
				if (ll p = dfs(e.to, t, min(f, e.c))) {
					e.c -= p, adj[e.to][e.rev].c += p;
					return p;
				}
		}
		return 0;
	}
	ll calc(int s, int t) {
		ll flow = 0; q[0] = s;
		rep(L,0,31) do { // 'int L=30' maybe faster for random data
			lvl = ptr = vi(sz(q));
			int qi = 0, qe = lvl[s] = 1;
			while (qi < qe && !lvl[t]) {
				int v = q[qi++];
				for (Edge e : adj[v])
					if (!lvl[e.to] && e.c >> (30 - L))
						q[qe++] = e.to, lvl[e.to] = lvl[v] + 1;
			}
			while (ll p = dfs(s, t, LLONG_MAX)) flow += p;
		} while (lvl[t]);
		return flow;
	}
	bool leftOfMinCut(int a) { return lvl[a] != 0; }
};

void solve() {
    long long n, p0;
    cin >> n >> p0;
    vector<long long> s1(n+1), s2(n+1), v1(n+1), v2(n+1), h1(n+1), h2(n+1);
    for (int i = 1; i <= n; i++) cin >> s1[i];
    for (int i = 1; i <= n; i++) cin >> s2[i];
    for (int i = 1; i <= n; i++) cin >> v1[i];
    for (int i = 1; i <= n; i++) cin >> v2[i];

    Dinic maxFlow(n+2);
    long long sum = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i+1; j <= n; j++) {
            long long contri_1 = max(s1[i] * v1[j], s1[j] * v1[i]);
            long long contri_2 = max(s2[i] * v2[j], s2[j] * v2[i]);
            maxFlow.addEdge(i, j, contri_1 + contri_2);
            maxFlow.addEdge(j, i, contri_1 + contri_2);
            sum += 2 * (contri_1 + contri_2);
            h1[i] += contri_1; h1[j] += contri_1;
            h2[j] += contri_2; h2[i] += contri_2;
        }
    }
    for (int i = 1; i <= n; i++) {
        long long contri_1 = 2 * p0 * v1[i];
        long long contri_2 = 2 * p0 * v2[i];
        maxFlow.addEdge(0, i, contri_1 + h1[i], 0);
        maxFlow.addEdge(i, n+1, contri_2 + h2[i], 0);
        sum += contri_1 + contri_2;
    }
    cout << (sum - maxFlow.calc(0, n+1)) / 2 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int T=1; 
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
