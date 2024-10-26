#include <bits/stdc++.h>
using namespace std;

using num = int64_t;
#define rep(i, a, b) for(num i = a; i < (b); ++i)
#define REPI(t, n) for (num t = 0; t < n; ++t)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
using ll = long long;
using pii = pair<int, int>;
using vi = vector<long long>;

pair<int, vi> hungarian(const vector<vi> &a) {
	if (a.empty()) return {0, {}};
	int n = sz(a) + 1, m = sz(a[0]) + 1;
	vi u(n), v(m), p(m), ans(n - 1);
	rep(i,1,n) {
		p[0] = i;
		int j0 = 0; // add "dummy" worker 0
		vi dist(m, INT_MAX), pre(m, -1);
		vector<bool> done(m + 1);
		do { // dijkstra
			done[j0] = true;
			int i0 = p[j0], j1, delta = INT_MAX;
			rep(j,1,m) if (!done[j]) {
				auto cur = a[i0 - 1][j - 1] - u[i0] - v[j];
				if (cur < dist[j]) dist[j] = cur, pre[j] = j0;
				if (dist[j] < delta) delta = dist[j], j1 = j;
			}
			rep(j,0,m) {
				if (done[j]) u[p[j]] += delta, v[j] -= delta;
				else dist[j] -= delta;
			}
			j0 = j1;
		} while (p[j0]);
		while (j0) { // update alternating path
			int j1 = pre[j0];
			p[j0] = p[j1], j0 = j1;
		}
	}
	rep(j,1,m) if (p[j]) ans[p[j] - 1] = j - 1;
	return {-v[0], ans}; // min cost
}


long long get_reward(long long val, vector<long long>& a, vector<long long>& prefix) {
    auto itr = lower_bound(a.begin(), a.end(), val);
    // cout << "lower bound: " << (int)(itr - a.begin()) << "\n";
    long long ans;
    if (itr == a.begin()) ans = 0;
    else {
        itr--;
        // cout << "real lower bound: " << (int)(itr - a.begin()) << "\n";
        ans =  prefix[(int)(itr - a.begin()) + 1];
    }  
    // cout << "reward for: " << val << " is " << ans << "\n";
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<array<long long, 2> > ap(n);
    vector<long long> a(n), b(n), c(n);
    for (int i = 0; i < n; i++) { cin >> ap[i][0]; a[i] = ap[i][0]; }
    for (int i = 0; i < n; i++) cin >> ap[i][1];
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < n; i++) cin >> c[i];
    sort(ap.begin(), ap.end());
    sort(a.begin(), a.end());

    vector<long long> prefix(n+1, 0);
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i-1] + ap[i-1][1];
    }

    vector<vector<long long> > cost(n+1, vector<long long>(n+1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cost[i+1][j+1] = -get_reward(b[i] + c[j], a, prefix);
        }
    }


    cout << -hungarian(cost).first << "\n";

    return 0;
}