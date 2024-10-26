#include "bits/stdc++.h"
using namespace std;

void solve(int case_no) {
  int r, c;
  cin >> r >> c;

  vector<string> mp(r);
  vector<vector<vector<int> > > cnt(r, vector<vector<int> >(c, vector<int>(4, 0)));
  vector<vector<vector<bool> > > valid(r, vector<vector<bool> >(c, vector<bool>(4, true)));
  vector<vector<bool> > visited(r, vector<bool>(c, false));
  int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};
  for (int i = 0; i < r; i++) cin >> mp[i];

  // dfs
  stack<array<int, 5> > q; // {x, y, start_x, start_y, start_d}

  // starting position can only be .
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (mp[i][j] == '.') {
          visited[i][j] = true;
          for (int d = 0; d < 4; d++) {
            int nx = i + dx[d], ny = j + dy[d];
            array<int, 5> entry = {nx, ny, i, j, d};
            if (nx >= 0 && nx < r && ny >= 0 && ny < c && mp[nx][ny] != '.') q.push(entry);
          }
      }
    }
  }

  while (!q.empty()) {
    auto cur = q.top();
    q.pop();

    int x = cur[0], y = cur[1];
    int start_x = cur[2], start_y = cur[3], start_d = cur[4];
    // cout << "dfs: " << mp[x][y] << " " << x << " " << y << " " << start_x << " " << start_y << "\n";
    if (visited[x][y]) { 
      if (mp[x][y] == '.' && (x != start_x || y != start_y)) {
        cnt[start_x][start_y][start_d] = 0;
        valid[start_x][start_y][start_d] = false;
      }
      continue; 
    }
    visited[x][y] = true;

    switch(mp[x][y]) {
      case 'W':
        if (valid[start_x][start_y][start_d]) cnt[start_x][start_y][start_d]++;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d], ny = y + dy[d];
          array<int, 5> entry = {nx, ny, start_x, start_y, start_d};
          if (nx >= 0 && nx < r && ny >= 0 && ny < c) q.push(entry);
        }
        break;
      case 'B':
        break;
      default:
        break;
    }
  }


  int ans = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      int total = 0;
      for (int d = 0; d < 4; d++) {
        total += cnt[i][j][d];
      }
      ans = max(ans, total);
    }
  }

  cout << "Case #" << case_no << ": " << ans << "\n";
}

int main(void) {
  ios::sync_with_stdio(false);

  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    solve(i);
  }

  return 0;
}
