#include <bits/stdc++.h>
using namespace std;

int most_significant(long long a) {
    int res = -1;
    while (a > 0) {
        res++;
        a >>= 1;
    }
    return res;
}

void solve() {
    long long l, r;
    cin >> l >> r;

    long long ms = most_significant(l ^ r);
    //     ms
    // l...11111
    long long a = l | ((1ll << ms) - 1), b = a + 1, c = (a == l ? r : l);

    cout << a << " " << b << " " << c << "\n"; // << ((a ^ b) + (b ^ c) + (a ^ c)) << "\n";
    
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}