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
	T _query(int v, int tl, int tr, int k) {
		if (tl == tr) {
			return tl;
		}
		else {
			int tm = (tl + tr) / 2;
			if (k < s[v*2+1]) return _query(v*2+1, tm+1, tr, k);
			else return _query(v*2, tl, tm, k-s[v*2+1]);
		}		
	}
	T query(int k) { 
		return _query(1, 0, n-1, k);
	}

};


int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Tree a = Tree(n+1, 0);
  vector<int> inv(n);
  for (int i = 0; i < n; i++) {
	cin >> inv[i];
	a.update(i, 1);
  }

  vector<int> ans(n);
  for (int i = n-1; i >= 0; i--) {
	ans[i] = a.query(inv[i]);
    a.update(ans[i], 0);
  }

  for (int el : ans) {
	cout << el+1 << " ";
  }
  cout << "\n";

  return 0;
}
