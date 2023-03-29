/*
 * Find all connected components. For each connected component, find the size of rectangular fence.
 * Get the minimum sized rectangular fence
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("fenceplan.in", "r", stdin); \
    freopen("fenceplan.out", "w", stdout);

struct bound {
    int x1;
    int x2;
    int y1;
    int y2;
};

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<pair<int, int>>& coordinates,
         int i, bound& b) {
    visited[i] = true;
    b.x1 = min(b.x1, coordinates[i].first);
    b.x2 = max(b.x2, coordinates[i].first);
    b.y1 = min(b.y1, coordinates[i].second);
    b.y2 = max(b.y2, coordinates[i].second);

    for (int neighbour : adj[i]) {
        if (!visited[neighbour]) {
            dfs(adj, visited, coordinates, neighbour, b);
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> coordinates(N);
    vector<vector<int>> adj(N);
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coordinates[i] = {x, y};
    }
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<bool> visited(N);
    int minPerimeter = INT_MAX;
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            bound b = {INT_MAX, 0, INT_MAX, 0};
            dfs(adj, visited, coordinates, i, b);

            int perimeter = 2*(b.x2 - b.x1) + 2*(b.y2 - b.y1);
            minPerimeter = min(minPerimeter, perimeter);
        }
    }

    cout << minPerimeter << '\n';

    return 0;
}
