#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

struct Node {
    // 1. left = max, right = min
    // 2. right = max, left = min
    // ar - al - (r-l) -> (ar-r) - (al-l)
    // al - ar - (r-l) -> (al+l) - (ar+r)
    long long min1, min2, max1, max2, ans1, ans2;
    Node() : min1(INF), min2(INF), max1(-INF), max2(-INF), ans1(0), ans2(0) {};
    Node(pair<int, int> x) : min1(x.first), min2(x.second), max1(x.first), max2(x.second), ans1(0), ans2(0) {};
};

struct Tree {
	typedef Node T;
	T unit = T();
	T f(T a, T b) { 
        Node res;
        res.min1 = min(a.min1, b.min1);
        res.min2 = min(a.min2, b.min2);
        res.max1 = max(a.max1, b.max1);
        res.max2 = max(a.max2, b.max2);
        res.ans1 = max({a.ans1, b.ans1, b.max1 - a.min1});
        res.ans2 = max({a.ans2, b.ans2, a.max2 - b.min2});
        return res; 
    } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = T()) : s(2*n, def), n(n) {}
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
    Tree st(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        st.update(i, Node(make_pair(a[i]-i, a[i]+i)));
    }
    
    Node ans = st.query(0, n);
    cout << max(ans.ans1, ans.ans2) << "\n";
    while (q--) {
        long long p, x;
        cin >> p >> x;
        p--;
        st.update(p, Node(make_pair(x-p, x+p)));
        Node ans = st.query(0, n);
        cout << max(ans.ans1, ans.ans2) << "\n";
    }
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