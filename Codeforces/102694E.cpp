#include "bits/stdc++.h"
using namespace std;
int n, q, timer = 0;
vector<set<int> > adj;
vector<int> in_time, out_time;
vector<bool> visited;
vector<double> v;

struct Tree {
	typedef double T;
	static const T unit = 1;
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
Tree sum;

void dfs(int u) {
  visited[u] = true;

  in_time[u] = timer++;
  for (int v : adj[u]) {
    if (visited[v]) continue;
    dfs(v);
  }
  out_time[u] = timer;
}


int main(void) {
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  cin >> n;

  adj.resize(n+1);
  in_time.resize(n+1, -1);
  out_time.resize(n+1, -1);
  visited.resize(n+1, false);
  v.resize(n+1, 1);
  sum = Tree(n+1, 0);

  for (int i = 0; i < n-1; i++) {
    int a, b;
    cin >> a >> b;
    adj[a].insert(b);
    adj[b].insert(a);
  }

  dfs(1);

  cin >> q;

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int x;
      double y;
      cin >> x >> y;
      
      sum.update(in_time[x], log(y));
    }
    else {
      int x, y;
      cin >> x >> y;
      double x_val = sum.query(in_time[x], out_time[x]), y_val = sum.query(in_time[y], out_time[y]);
      // cout << x_val << " " << y_val << "\n";
      double ans = max(log(1e-9), min(log(1e9), x_val - y_val));
      cout << exp(ans) << "\n";
    }
  }

  return 0;
}
