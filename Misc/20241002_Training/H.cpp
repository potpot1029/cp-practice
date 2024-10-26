#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;

    if (a - b <= c) {
        cout << "NO\n";
    }
    else if (b == 0 && c == 0) {
        if (a == 1) cout << "YES\n0\n";
        else cout << "YES\n1\n";
    }
    else {
        cout << "YES\n";
        cout << (b+c)*2+1 << "\n";
    }

    return 0;
}