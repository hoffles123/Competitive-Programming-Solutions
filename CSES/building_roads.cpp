// min no. of roads needed = no. of connected components - 1
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<unordered_set<int>>& components, int i, int count) {
    visited[i] = true;
    if (components.size() < count) {
        components.push_back({i});
    } else {
        components[count - 1].insert(i);
    }

    for (int neighbour : adj[i]) {
        if (!visited[neighbour]) {
            dfs(adj, visited, components, neighbour, count);
        }
    }
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<unordered_set<int>> components;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    vector<bool> visited(n + 1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int count = 1;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, components, i, count);
            count++;
        }
    }

    cout << components.size() - 1 << '\n';
    for (int i = 0; i < components.size() - 1; i++) {
        cout << *components[i].begin() << " " << *components[i + 1].begin() << '\n';
    }

    return 0;
}
