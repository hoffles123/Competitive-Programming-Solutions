#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("factory.in", "r", stdin); \
    freopen("factory.out", "w", stdout);

void dfs(vector<vector<int>>& adj,
         vector<unordered_set<int>>& canArriveFrom,
         vector<bool>& visited,
         int node, int origin) {
    for (const auto& canArrive : canArriveFrom[origin]) {
        canArriveFrom[node].insert(canArrive);
    }
    canArriveFrom[node].insert(origin);
    visited[node] = true;
    for (const auto& neighbour : adj[node]) {
        if (!visited[neighbour]) {
            dfs(adj, canArriveFrom, visited, neighbour, origin);
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<int>> adj(N + 1);
    vector<unordered_set<int>> canArriveFrom(N + 1);
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        vector<bool> visited(N + 1);
        dfs(adj, canArriveFrom, visited, y, x);
        adj[x].push_back(y);
    }

    for (int i = 0; i < canArriveFrom.size(); i++) {
        if (canArriveFrom[i].size() == N - 1) {
            cout << i << '\n';
            return 0;
        }
    }

    cout << -1 << '\n';

    return 0;
}
