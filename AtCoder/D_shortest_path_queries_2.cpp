#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<long long>> dist(n+1, vector<long long>(n+1, INF));
	for (int i = 0; i < m; i++) {
		int a, b; long long c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}

	long long ans = 0;
	for (int k = 1; k <= n; k++) {
		vector<vector<long long>> nxt_dist(n+1, vector<long long>(n+1, INF));
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				nxt_dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
				if (nxt_dist[i][j] < INF) ans += nxt_dist[i][j];
			}
		}
		dist = nxt_dist;
	}
	cout << ans << "\n";
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