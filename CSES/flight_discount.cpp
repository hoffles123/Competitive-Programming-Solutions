/*
 * modified dijkstra's algorithm
 * have a 2D dist vector tracking if we have or have not used the discount till vertex i
 * if we have not used discount till vertex i, we have 2 options
 * 1. used the discount now
 * 2. dont use the discount now
 * throw both options into the heap for processing
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;
using ii = pair<ll, ll>;
using iii = tuple<ll, ll, bool>;

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

    vector<vector<ll>> dist(n, vector<ll>(2, LLONG_MAX));
    dist[0] = {0, 0};
    priority_queue<iii, vector<iii>, greater<>> minHeap;
    minHeap.emplace(0, 0, false);

    while(!minHeap.empty()) {
        auto [currDist, node, used] = minHeap.top();
        minHeap.pop();
        if (currDist != dist[node][used])
            continue;
        for (auto [neighbour, weight] : adj[node]) {
            if (!used) {
                if (dist[node][used] + weight/2 < dist[neighbour][true]) {
                    dist[neighbour][true] = dist[node][used] + weight/2;
                    minHeap.emplace(dist[neighbour][true], neighbour, true);
                }
            }
            if (dist[node][used] + weight < dist[neighbour][used]) {
                dist[neighbour][used] = dist[node][used] + weight;
                minHeap.emplace(dist[neighbour][used], neighbour, used);
            }
        }
    }

    cout << dist[n - 1][true] << '\n';

    return 0;
}
