#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

double pi() {
    return atan(1) * 4.0;
}

double cal_angle(Point p) {
    return atan2(p.y, p.x) + 2 * pi();
}

void solve() {
    int n, k;
    cin >> n >> k;

    vector<Point> islands(n);
    for (int i = 0; i < n; i++) {
        cin >> islands[i].x >> islands[i].y;
    }

    sort(islands.begin(), islands.end(), [](const auto& a, const auto &b) {
        return cal_angle(a) < cal_angle(b);
    });

    vector<pair<double, int>> angles;
    for (int i = 0; i < islands.size(); i++) {        
        double cur_angle = cal_angle(islands[i]);
        if (angles.size() == 0 || abs(cur_angle - angles[angles.size()-1].first) > 1e-7) {
            angles.push_back(make_pair(cur_angle, 1));
        }
        else {
            angles[angles.size()-1].second++;
        }
    }
    // add 360o
    int sz = angles.size();
    for (int i = 0; i < sz; i++) {
        angles.push_back(make_pair(angles[i].first + 2 * pi(), angles[i].second));
    }
    double ans = 0.0;
    int l = 0, r = 0, cur_cnt = angles[0].second;
    int prev_l = 0;
    while (r < angles.size()) {
        
        while (r+1 <= l + sz && r+1 < angles.size() && (cur_cnt < k + angles[l].second || l == r)) {
            r++;
            cur_cnt += angles[r].second;
        }

        // cout << "test " << l << " " << r << " " << cur_cnt << " " << angles[r].first - angles[l].first << "\n";
        ans = max(ans, angles[r].first - angles[l].first);

        
        cur_cnt -= angles[l++].second;
        if (l == angles.size()-1) break;
    }
    cout << fixed << setprecision(10) << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}