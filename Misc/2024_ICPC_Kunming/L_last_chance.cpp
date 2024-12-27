#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<long long> f_healths(n), s_healths(m);
    for (int i = 0; i < n; i++) cin >> f_healths[i];
    for (int i = 0; i < m; i++) cin >> s_healths[i];
    sort(f_healths.begin(), f_healths.end());
    sort(s_healths.begin(), s_healths.end());
    long long a_damage = 0;
    // check attack
    for (int i = 0; i < n; i++) {
        int tmp = i;
        while (f_healths[i] == 1) {
            i++;
        }
        if (tmp != i) i--;
        a_damage++;
    }
    long long damage = 0, f_ptr = 0, s_ptr = 0;
    while (s_ptr < m) {
        long long tmp_f_ptr = f_ptr, tmp_s_ptr = s_ptr;
        // cout << "test " << f_ptr << " " << s_ptr << " " << damage << " " << a_damage << "\n";
        if (f_ptr < n && f_healths[f_ptr] <= s_healths[s_ptr] && f_healths[f_ptr]-damage-1 <= 0) {
            damage++;
            f_ptr++;
        }
        else if (s_ptr < m && s_healths[s_ptr]-damage-a_damage <= 0) {
            a_damage -= max(s_healths[s_ptr]-damage, 0ll);
            damage++;
            s_ptr++;
        }
        if (f_ptr == tmp_f_ptr && s_ptr == tmp_s_ptr) break;
    }
    // cout << "test " << f_ptr << " " << s_ptr << " " << damage << " " << a_damage << "\n";
    if (s_ptr != m) cout << "No\n";
    else cout << "Yes\n";
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