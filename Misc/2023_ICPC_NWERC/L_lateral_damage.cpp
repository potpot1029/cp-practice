#include <bits/stdc++.h>
using namespace std;

int query(int x, int y, vector<vector<int>> &status) {
    if (status[x][y] != -1) return status[x][y];
    cout << x+1 << " " << y+1 << "\n";
    cout.flush();
    string res = "miss";
    cin >> res;

    if (res == "miss") status[x][y] = 0;
    else if (res == "hit") status[x][y] = 1;
    else status[x][y] = 2;
    return status[x][y];
}

bool in_range(int x, int y, int n) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

int main() {
    ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    // x x x x o x x x x o
    // x x x o x x x x o x
    // x x o x x x x o x x
    // x o x x x x o x x x
    // o x x x x o x x x x
    // x x x x o x x x x o
    vector<vector<int>> status(n, vector<int>(n, -1));
    for (int i = 0; i < n; i++) {
        for (int j = 4-(i % 5); j < n; j += 5) {
            query(i, j, status);
            if (status[i][j] == 1) {
                int dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};
                for (int d = 0; d < 4; d++) {
                    int nx = i + dx[d], ny = j + dy[d];
                    while (in_range(nx, ny, n) && query(nx, ny, status) != 0) {
                        if (status[nx][ny] == 2) {
                            k--;
                            if (k == 0) return 0;
                            status[nx][ny] = 1;
                        }
                        nx += dx[d];
                        ny += dy[d];
                    }
                }
            }
        }
    }
    return 0;
}