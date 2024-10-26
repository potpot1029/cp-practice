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

const int MAXN = 1e5 + 10;
int color[MAXN];
int dp[MAXN];
vector<int> adj[MAXN];

map<int, int>* dfs(int u) {
	vector<map<int, int>*> to_merge;
	int ans = 0;
	if (adj[u].size() == 0) {
		map<int, int>* single = new map<int, int>();
		(*single)[color[u]] = 1;
		dp[u] = 1;
		// cout << u << " " << dp[u] << "\n";
		return single;
	}
	for (int v : adj[u]) {
		auto res_sub = dfs(v);
		to_merge.push_back(res_sub);
		dp[u] += dp[v];
	}


	// merge
	map<int, int>* res; 
	sort (to_merge.begin(), to_merge.end(), [] (const auto& a, const auto& b) {
		return a->size() > b->size();
	});

	res = to_merge[0];
	int max_cnt = 1;
	for (int i = 1; i < to_merge.size(); i++) {
		int no_color = (*to_merge[i])[0];
		for (auto it = (*to_merge[i]).begin(); it != (*to_merge[i]).end(); it++) {
			(*res)[it->first] += it->second;
			max_cnt = max(max_cnt, (*res)[it->first]);
		}
	}

	map<int, int> *new_res = res;
	if (max_cnt > 1) {
		new_res = new map<int, int>();
		for (auto it = (*res).begin(); it != (*res).end(); it++) {
			// cout << "now at: " << u << " test: " << it->first << " " << it->second << "\n";
			if (max_cnt == it->second) {
				(*new_res)[it->first] = 1;
				// cout << "retain: " << it->first << " " << (*new_res)[it->first] << "\n";
			}
		}
	}

	dp[u] -= max_cnt - 1;
	// cout << u << " " << dp[u] << " " << max_cnt << "\n";
	return new_res;
}


int main() {
	ios::sync_with_stdio(0);

	int n;
	cin >> n;

	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		adj[p].push_back(i+1);
	}
	
	for (int i = 1; i <= n; i++) {
		cin >> color[i];
	}

	dfs(1);
	cout << dp[1] << "\n";
}
