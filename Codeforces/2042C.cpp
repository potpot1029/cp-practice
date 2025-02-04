#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n; long long k;
    cin >> n >> k;
    string fishes;
    cin >> fishes;
    vector<long long> diff(n, 0);
    diff[n-1] = (fishes[n-1] == '1' ? +1 : -1);
    for (int i = n-2; i >= 1; i--) {
        diff[i] = diff[i+1] + (fishes[i] == '1' ? +1 : -1);
        // cout << i << " " << diff[i] << "\n";
    }
    sort(diff.rbegin(), diff.rend());
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        // cout << i << " " << diff[i] << "\n";
        sum += diff[i];
        if (sum >= k) {
            cout << i+2 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
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