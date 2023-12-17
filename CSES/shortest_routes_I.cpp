// dijkstra's algorithm SSSP
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;
using ii = pair<ll, ll>;

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<ii>> adj(n);
    while(m--) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        adj[a].emplace_back(b, c);
    }

    vector<ll> dist(n, LLONG_MAX);
    dist[0] = 0;
    priority_queue<ii, vector<ii>, greater<>> minHeap;
    minHeap.emplace(0, 0);

    while(!minHeap.empty()) {
        auto [currDist, node] = minHeap.top();
        minHeap.pop();
        if (currDist != dist[node])
            continue;
        for (auto [neighbour, weight] : adj[node]) {
            if (dist[node] + weight < dist[neighbour]) {
                dist[neighbour] = dist[node] + weight;
                minHeap.emplace(dist[neighbour], neighbour);
            }
        }
    }

    for (auto d : dist) {
        cout << d << " ";
    }
    cout << endl;

    return 0;
}
