#include "bits/stdc++.h"
using namespace std;
vector<int> euler_tour;
vector<set<int> > adj;
vector<bool> visited;

void dfs(int u) {
  euler_tour.push_back(u);
  visited[u] = true;

  for (int v : adj[u]) {
    if (visited[v]) continue;
    dfs(v);
    euler_tour.push_back(u);
  }
}

int main(void) {
  ios::sync_with_stdio(false);

  int n, m, k;
  cin >> n >> m >> k;

  adj.resize(n+1);
  visited.resize(n+1, false);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    adj[x].insert(y);
    adj[y].insert(x);
  }
  int limit = ceil((double) 2 * n / k);

  dfs(1);

  for (int i = 0; i < k; i++) {
    int cnt = min(limit, (int) euler_tour.size() - i * limit);
    if (cnt <= 0) { // visit any node if all nodes are visited
      cout << "1 1\n";
      continue;
    }
    cout << cnt << " ";
    for (int j = 0; j < cnt; j++)  {
      cout << euler_tour[limit * i + j] << " ";
    }
    cout << "\n";
  }

  return 0;
}
