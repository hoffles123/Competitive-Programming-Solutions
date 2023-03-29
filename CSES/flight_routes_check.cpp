// connected components (disconnected components)
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<unordered_set<int>>& components, int i, int count) {
    visited[i] = true;
    if (components.size() < count + 1) {
        components.emplace_back();
    }
    components[count].insert(i);
    for (int neighbour : adj[i]) {
        if (!visited[neighbour]) {
            dfs(adj, visited, components, neighbour, count);
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n + 1);
    while(m--) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    vector<bool> visited(n + 1);
    vector<unordered_set<int>> components;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            dfs(adj, visited, components, i, count);
            count++;
        }
    }

    if (components.size() == 1) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
        cout << *components[0].begin() + 1 << " " << *components[1].begin() + 1 << '\n';
    }

    return 0;
}
