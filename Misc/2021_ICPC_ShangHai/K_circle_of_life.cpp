#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
	cin >> n;

	if (n == 3) {
		cout << "Unlucky\n";
		return;
	}

	bool first = false; // 01, 10
	// 100110
	// 011001
	// 100110
	if (n % 2 == 1) {
		cout << "100";
		n -= 3;
		first = true;
	}

	while (n > 0) {
		cout << (first ? "01" : "10");
		first = (first ? false : true);
		n -= 2;
	}
	cout << "\n";
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
