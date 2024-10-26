#include "bits/stdc++.h"
using namespace std;

struct Tree {
	typedef int T;
	static const T unit = INT_MIN;
	T f(T a, T b) { return a + b; } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
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

int main(void) {
  ios::sync_with_stdio(false);

  int n;
  cin >> n;

  Tree inv = Tree(n, 0);
  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];

  vector<int> ans;
  for (int i = 0; i < n; i++) {
    cout << inv.query(p[i], n) << " \n"[i == n-1];
    inv.update(p[i]-1, 1);
  }

  return 0;
}
