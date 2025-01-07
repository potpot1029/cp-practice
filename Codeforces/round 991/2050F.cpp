#include <bits/stdc++.h>
using namespace std;

struct Tree {
	typedef int T;
	static constexpr T unit = 0;
	T f(T a, T b) { return __gcd(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;) {
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
            // cout << pos << " " << s[pos] << "\n";
        }
			
	}
	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    Tree st(n);
    for (int i = 1; i < n; i++) {
        // cout << "update: " << i << "\n";
        st.update(i-1, abs(a[i]-a[i-1]));
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        if (l == r) cout << 0 << " ";
        else cout << st.query(l, r) << " ";
    }
    cout << "\n";
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