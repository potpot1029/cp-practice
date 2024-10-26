#include "bits/stdc++.h"
using namespace std;

void dfs(int u, int cc, vector<vector<pair<int, int> > > &adj, vector<bool> &visited, vector<int> &component) {
  visited[u] = true;
  component[u] = cc;

  for (int i = 0; i < adj[u].size(); ++i) {
    int v = adj[u][i].first;
    if (!visited[v]) {
      dfs(v, cc, adj, visited, component);
    }
  }
}


int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  while (t--) {
    int n, q;
    cin >> n >> q;

    map<string, set<int> > colors_to_cities;
    vector<string> cities_to_colors(n);

    for (int i = 0; i < n; ++i) {
      string color_pair;
      cin >> color_pair;

      colors_to_cities[color_pair].insert(i);
      cities_to_colors[i] = color_pair;
    }

    for (int i = 0; i < q; ++i) {
      int x, y;
      cin >> x >> y;
      x--; y--;

      if (x > y) swap(x, y);

      // if the color pairs of the cities intersect
      if (cities_to_colors[x][0] == cities_to_colors[y][0] 
      || cities_to_colors[x][0] == cities_to_colors[y][1] 
      || cities_to_colors[x][1] == cities_to_colors[y][0] 
      || cities_to_colors[x][1] == cities_to_colors[y][1]) {
        cout << y-x << "\n";
      }
      else {
        // find a city that match one of the color of both cities
        int ans = 1e9;
        for (auto &[color, cities] : colors_to_cities) {
          if (color == cities_to_colors[x] || color == cities_to_colors[y]) continue;

          auto it = cities.lower_bound(x);
          if (it != cities.end()) {   // *it >= x
            if (*it < y) ans = min(ans, y-x);
            else ans = min(ans, (*it - y) + (*it - x));
          }
          if (it != cities.begin()) { // *it < x
            it--;
            ans = min(ans, (y - *it) + (x - *it));
          }
        }
        cout << (ans == 1e9 ? -1 : ans) << "\n";
      }
    }
  }

  return 0;
}
