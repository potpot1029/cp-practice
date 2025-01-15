#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2001;

void solve() {
	int n, m;
    cin >> n >> m;
	vector<pair<int, int>> edges;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
		edges.push_back(make_pair(a, b));
    }
	vector<bitset<MAXN>> travel(MAXN);
	for (int i = 1; i <= n; i++) travel[i][i] = 1;
	for (int i = 0; i < edges.size(); i++) {
		travel[edges[i].first][edges[i].second] = 1;
	}
	int q;
	cin >> q;
	vector<pair<int, int>> queries(q);
	vector<int> ans(q, -1);
	for (int i = 0; i < q; i++) {
		cin >> queries[i].first >> queries[i].second;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (travel[j][i]) travel[j] |= travel[i];
		}
		for (int j = 0; j < q; j++) {
			if (ans[j] == -1 && travel[queries[j].first][queries[j].second]) 
				ans[j] = i;
		}
	}
	for (int i = 0; i < q; i++) {
		if (ans[i] == -1) cout << -1 << "\n";
		else cout << max({ans[i], queries[i].first, queries[i].second}) << "\n";
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