#include "bits/stdc++.h"
using namespace std;

// https://usaco.guide/gold/dsu?lang=cpp
class DisjointSets {
  private:
	vector<int> parents;
	vector<int> sizes;

  public:
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}

	/** @return the "representative" node in x's component */
	int find(int x) {
		return parents[x] == x ? x : (parents[x] = find(parents[x]));
	}

	/** @return whether the merge changed connectivity */
	bool unite(int x, int y) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) { return false; }

		if (sizes[x_root] < sizes[y_root]) { swap(x_root, y_root); }
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}

	/** @return whether x and y are in the same connected component */
	bool connected(int x, int y) { return find(x) == find(y); }
};

void find_chain(vector<pair<int, int> > &edges, DisjointSets &dsu, int a, int b) {
  if (dsu.connected(a, b)) {
    return ;
  }

  cout << "? " << a << " " << b << "\n";
  cout.flush();

  int m;
  cin >> m;

  if (m == a) {
    edges.push_back(make_pair(a, b));
    dsu.unite(a, b);
    return;
  }

  find_chain(edges, dsu, a, m);
  find_chain(edges, dsu, m, b);
}

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int> > edges;
  DisjointSets dsu(n+1);

  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      find_chain(edges, dsu, i, j);
    }
  }


  cout << "! ";
  for (auto edge : edges) {
    cout << edge.first << " " << edge.second << " ";
  }
  cout << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;
  while (t--) {
    solve();
  }

  return 0;
}
