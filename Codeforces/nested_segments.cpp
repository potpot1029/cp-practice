#include "bits/stdc++.h"
using namespace std;

struct Tree {
	typedef int T;
	static const T unit = INT_MIN;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(4*n, def), n(n) {}
	void _update(int v, int tl, int tr, int pos, T val) {
		if (tl == tr) {
			s[v] = val;
		} else {
			int tm = (tl + tr) / 2;
			if (pos <= tm)
				_update(v*2, tl, tm, pos, val);
			else
				_update(v*2+1, tm+1, tr, pos, val);
			s[v] = f(s[v*2],  s[v*2+1]);
		}
	}
	void update(int pos, T val) {
		_update(1, 0, n-1, pos, val);
	}
	T _query(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		}
		else if (l == tl && r == tr) {
			return s[v];
		}
		else {
			int tm = (tl + tr) / 2;
			int left_res = _query(v*2, tl, tm, l, min(tm, r));
			int right_res = _query(v*2+1, tm+1, tr, max(tm+1, l), r);
	
			return f(left_res, right_res);
		}		
	}
	T query(int b, int e) { // query [b, e)
		return _query(1, 0, n-1, b, e);
	}

};


int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Tree a = Tree(n*2, 0);
  array<int, 2> init = {-1, -1};
  vector<int> ans(n+1);
  vector<array<int, 2> > occ(n+1, init);
  for (int i = 0; i < 2*n; i++) {
	int x;
	cin >> x;
	if (occ[x][0] != -1) {
		occ[x][1] = i;
		ans[x] = a.query(occ[x][0], i);
		a.update(occ[x][0], 1);
	}
	else {
		occ[x][0] = i;
	}
  }

  for (int i = 1; i <= n; i++) {
	cout << ans[i] << " ";
  }
  cout << "\n";

  return 0;
}
