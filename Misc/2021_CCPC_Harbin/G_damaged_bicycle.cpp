#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e18;

struct Edge {
    int weight, to;
    Edge(int to, int weight) : to(to), weight(weight) {}
};

struct Bicycle {
    int loc, prob;
    Bicycle(int loc, int prob) : loc(loc), prob(prob) {}
};

vector<vector<Edge>> adj;
vector<vector<long long>> dis;
vector<vector<double>> dp;
vector<Bicycle> bicycles;
int walk, ride, n, m, num_bicycles;

void dijkstra(int start, int idx=0) {
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push(make_pair(0, start));
    dis[idx][start] = 0;
    vector<bool> vis(n+1, false);
    while (!pq.empty()) {
        auto cur = pq.top(); pq.pop();
        long long cur_dist = cur.first;
        int u = cur.second;

        if (vis[u]) continue;

        for (auto nxt : adj[u]) {
            long long nxt_weight = nxt.weight;
            int v = nxt.to;
            if (dis[idx][u] + nxt_weight < dis[idx][v]) {
                dis[idx][v] = dis[idx][u] + nxt_weight;
                pq.push(make_pair(dis[idx][v], v));
            }
        }
    }   
}

double dfs(int state, int idx) {
    if (dp[state][idx] != 0) return dp[state][idx];


    double exp_walk = (double) dis[idx][n] / walk * (double) bicycles[idx].prob / 100;
    double exp_ride = (double) dis[idx][n] / ride * (double) (100 - bicycles[idx].prob) / 100;
    double res = exp_walk + exp_ride;
    // cout << idx << " " << exp_walk << " " << exp_ride << " " << res << "\n";

    for (int i = 0; i < num_bicycles; i++) {
        if (state & (1ll << i)) continue;
        long long nxt_state = state | (1ll << i);
        int nxt_idx = i, nxt_node = bicycles[i].loc;
        double exp_no_ride = ((double) dis[idx][nxt_node] / walk + dfs(nxt_state, nxt_idx)) * (double) bicycles[idx].prob / 100;

        res = min(res, exp_ride + exp_no_ride);
    }

    
    return dp[state][idx] = res;
}


void solve() {
    cin >> walk >> ride >> n >> m;

    adj.assign(n+1, vector<Edge>());

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(Edge(v, w));
        adj[v].push_back(Edge(u, w));
    }
    
    cin >> num_bicycles;

    dis.assign(num_bicycles+1, vector<long long>(n+1, INF));

    dijkstra(1, num_bicycles);

    if (dis[num_bicycles][n] == INF) {
        cout << -1 << "\n";
        return;
    }
    if (num_bicycles == 0) {
        cout << (double) dis[num_bicycles][n] / walk << "\n";
        return;
    }

    bicycles.assign(num_bicycles+1, Bicycle(0, 0));
    for (int i = 0; i < num_bicycles; i++) {
        int a, p;
        cin >> bicycles[i].loc >> bicycles[i].prob;
    }
    bicycles[num_bicycles] = Bicycle(1, 100); 
    for (int i = 0; i < num_bicycles; i++) dijkstra(bicycles[i].loc, i);
    
    dp.assign((1ll << (num_bicycles)), vector<double>(num_bicycles+1, 0));
    dfs(0, num_bicycles);
    cout << fixed << setprecision(10) << dp[0][num_bicycles] << "\n";
}



int main() {
    ios::sync_with_stdio(false);
    int T=1;
    // cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}