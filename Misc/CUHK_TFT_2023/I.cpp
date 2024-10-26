#include "bits/stdc++.h"
using namespace std;

struct e {
  e(int from=0, int to=0, bool deleted=true): from(from), to(to), deleted(deleted) {};
  int from;
  int to;
  bool deleted;
};

vector<vector<int> > adj;
vector<e> edges;
vector<bool> node_delete, visited;

void dfs(int u) {
  // cout << "visiting: " << u << "\n";
  visited[u] = true;
  for (int idx : adj[u]) {
    if (edges[idx].deleted) continue;
    if (node_delete[edges[idx].to]) continue;
    if (visited[edges[idx].to]) continue;
    dfs(edges[idx].to);
  }
}

int main(void) {
  ios::sync_with_stdio(false);

  int n, m, q;
  cin >> n >> m >> q;

  adj.resize(n+1);
  node_delete.resize(n+1, false);
  visited.resize(n+1, false);


  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    edges.push_back(e(x, y, false));
    adj[x].push_back(i);
  }

  while (q--) {
    vector<int> ans;
    for (int i = 1; i <= n; i++) visited[i] = false;

    int delete_idx;
    cin >> delete_idx;
    delete_idx--;
    e delete_edge = edges[delete_idx];

    // delete edge with idx=delete_idx
    if (!delete_edge.deleted) {
      edges[delete_idx].deleted = true;
      dfs(1);
      for (int i = 2; i <= n; i++) {
        if (!visited[i] && !node_delete[i]) {
          ans.push_back(i);
          node_delete[i] = true;
        }
      }
    }

    cout << ans.size() << " ";
    for (int k : ans) {
      cout << k << " ";
    }
    cout << "\n";
  }
  return 0;
}
