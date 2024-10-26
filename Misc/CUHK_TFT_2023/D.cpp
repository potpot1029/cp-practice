#include "bits/stdc++.h"
using namespace std;
struct e {
  e(int from=0, int to=0, bool deleted=true): from(from), to(to), deleted(deleted) {}
  int from;
  int to;
  bool deleted;
};

vector<vector<int> > adj;
vector<bool> visited;
vector<e> edges;
vector<int> ans, colors;

int dfs(int u) {
  visited[u] = true;

  colors[u] = 1; // active node
  for (int idx : adj[u]) {
    int v = edges[idx].to;
    if (visited[v] && colors[v] == 1) {
      cnt[idx] += 1;
      continue;
    }
    cnt[idx] += dfs(v);
  }
  colors[u] = 2; // inactive node
  return 
}

void solve() {
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < adj.size(); i++) adj.clear();
  adj.resize(n+1);
  visited.clear();
  visited.resize(n+1, false);
  edges.clear();
  ans.clear();
  colors.clear();
  colors.resize(n+1, 0);

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    edges.push_back(e(x, y, false));
    adj[x].push_back(i);
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  cout << ans.size() << "\n";
  for (int el : ans) {
    cout << el << " ";
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
