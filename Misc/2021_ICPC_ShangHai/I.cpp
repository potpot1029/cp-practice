#include <bits/stdc++.h>
using namespace std;

const int MAXPOINT = 5204;
const int BASE = MAXPOINT / 2;
const long long INF = -1e18;

bool in_range(int x) {
    return x >= 0 && x <= MAXPOINT;
}

int main() {
    ios::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;

    vector<pair<long long, int>> cards(n+1);
    for (int i = 1; i <= n; i++) {
        long long v; int t;
        cin >> v >> t;
        cards[i] = make_pair(v, t);
    }

    vector<vector<vector<long long>>> dp(2, vector<vector<long long>>(MAXPOINT+1, vector<long long>(k+1, INF)));
    dp[0][BASE][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= MAXPOINT; j++) {
            for (int m = k; m >= 0; m--) {
                dp[1][j][m] = max(dp[1][j][m], dp[0][j][m]);
            }
        }

        for (int j = 0; j <= MAXPOINT; j++) {
            for (int m = k; m >= 0; m--) {
                // put in S
                if (in_range(j + cards[i].second)) dp[1][j+cards[i].second][m] = max(dp[1][j+cards[i].second][m], dp[0][j][m] + cards[i].first);
                // put in T
                if (in_range(j - cards[i].second)) dp[1][j-cards[i].second][m] = max(dp[1][j-cards[i].second][m], dp[0][j][m] + cards[i].first);
                // double
                if (m + 1 <= k && in_range(j + 2 * cards[i].second)) dp[1][j+2*cards[i].second][m+1] = max(dp[1][j+2*cards[i].second][m+1], dp[0][j][m] + cards[i].first);
                if (m + 1 <= k && in_range(j - 2 * cards[i].second)) dp[1][j-2*cards[i].second][m+1] = max(dp[1][j-2*cards[i].second][m+1], dp[0][j][m] + cards[i].first);
            }
        }

        for (int j = 0; j <= MAXPOINT; j++) {
            for (int m = k; m >= 0; m--) {
                dp[0][j][m] = dp[1][j][m];
                // if (dp[0][j][m] >= 0) cout << i << " " << j << " " << m <[0]< " " << dp[0][j][m] << "\n";
            }
        }
    }


    long long ans = 0;
    for (int i = 0; i <= k; i++) {
        ans = max(ans, dp[0][BASE][i]);
    }
    cout << ans << "\n";
    return 0;
}