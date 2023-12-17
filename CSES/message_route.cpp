// bfs - shortest path unweighted graph with distance and path reconstruction
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

vector<vector<int>> adj;

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    adj.resize(n);

    while(m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].emplace_back(b);
        adj[b].emplace_back(a);
    }

    queue<int> q;
    vector<int> dist(n, 0);
    vector<int> parents(n);
    vector<bool> visited(n);
    visited[0] = true;
    q.push(0);
    // src = 0, dest = n - 1;
    while(!q.empty()) {
        int node = q.front();
        q.pop();
        for (const int& neighbour : adj[node]) {
            if (!visited[neighbour]) {
                parents[neighbour] = node;
                dist[neighbour] = dist[node] + 1;
                visited[neighbour] = true;
                q.push(neighbour);
            }
        }
    }

    if (dist[n - 1] == 0) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    cout << dist[n - 1] + 1 << '\n';
    vector<int> path;
    int parent = n - 1;
    while(parent != 0) {
        path.push_back(parent + 1);
        parent = parents[parent];
    }
    path.push_back(1);
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i] << " ";
    }
    cout << '\n';


    return 0;
}
