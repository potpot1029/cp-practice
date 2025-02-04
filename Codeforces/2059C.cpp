#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> idx(n, 0);
    int j = 0;
    while (true) {
        bool done = true;
        for (int i = 0; i < n; i++) {
            if (idx[i] == j && a[i][n-j-1] == 1) {
                idx[i]++;
                done = false;
            }
        }
        if (done) {
            break;
        }
        j++;
    }
    sort(idx.begin(), idx.end());
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (idx[i] >= ans) {
            ans++;
        }
    }
    cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}