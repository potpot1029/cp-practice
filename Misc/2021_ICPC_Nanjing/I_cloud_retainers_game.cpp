#include<bits/stdc++.h>
using namespace std;

struct Point {
	int x, y, type; // type 1 = coin
};

bool cmp(Point a, Point b) {
	return a.x < b.x;
}

void solve() {
    int H, n, m;
	cin >> H >> n;
	vector<Point> objs;
	for (int i = 0; i < n; i++) {
		int x, y, type=0;
		cin >> x >> y;
		objs.push_back((Point){x, y, type});
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int x, y, type=1;
		cin >> x >> y;
		objs.push_back((Point){x, y, type});
	}
	sort(objs.begin(), objs.end(), cmp);

	map<int, int> dp;
	dp[0] = 1;
	int ans = 1;
	for (int i = 0; i < objs.size(); i++) {
		int down_k = (objs[i].x + objs[i].y) % (2 * H);
		int up_k = (2 * H - objs[i].y + objs[i].x) % (2 * H);

		if (objs[i].type == 1) {
			if (dp[down_k]) dp[down_k]++;
			if (dp[up_k]) dp[up_k]++;
		}
		else {
			int best = max(dp[down_k], dp[up_k]);
			dp[down_k] = dp[up_k] = best;
		}
		ans = max(ans, max(dp[down_k], dp[up_k]));
	}
	cout << ans-1 << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    int T=1; 
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
