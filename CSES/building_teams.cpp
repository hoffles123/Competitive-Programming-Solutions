// bipartite graph coloring
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

bool isBipartite = true;

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& colors, int i, bool color) {
    visited[i] = true;
    colors[i] = color;

    for (int neighbour : adj[i]) {
        if (visited[neighbour]) {
            if (colors[neighbour] == color) isBipartite = false;
        } else {
            dfs(adj, visited, colors, neighbour, !color);
        }
    }
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    vector<bool> colors(n + 1);

    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, colors, i, true);
        }
    }

    if (!isBipartite) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }

    for (int i = 1; i <= n; i++) {
        if (colors[i]) {
            cout << "1" << " ";
        } else {
            cout << "2" << " ";
        }
    }
    cout << endl;

    return 0;
}
