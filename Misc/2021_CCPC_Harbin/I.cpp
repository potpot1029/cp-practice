#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> bits(35, 0);
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;

        for (int j = 0; j < 35; j++) {
            if ((a >> j) & 1) bits[j]++;
        }
    }

    long long ans = 0;
    while (true) {
        int zero_pos = INT_MAX;
        bool flag = false;
        for (int i = 0; i < 35; i++) {
            // cout << "test: " << i << " " << bits[i] << " " << zero_pos << "\n";
            if (bits[i] == 0) {
                zero_pos = min(zero_pos, i);
            }
            else {
                flag = true;
                bits[i]--;
                if (zero_pos != INT_MAX) {
                    bits[zero_pos]++;
                    zero_pos = INT_MAX;
                    i--;
                }
            }
        }
        if (flag) ans++;
        else break;
    }
    cout << ans << "\n";
}

int main(){
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

}