/*
 * maximum number of edges in bipartite graph is left side * right side
 * there are already n - 1 exisitng edges
 * ans = l * r - (n - 1)
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

vector<vector<int>> adj;
vector<bool> visited;
vector<bool> colours;

void dfs(int i, bool colour) {
    visited[i] = true;
    colours[i] = colour;

    for (const int& neighbour : adj[i]) {
        if (!visited[neighbour]) {
            dfs(neighbour, !colour);
        }
    }
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    adj.resize(n);
    visited.resize(n);
    colours.resize(n);
    n--;
    while(n--) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < adj.size(); i++) {
        if (!visited[i]) {
            dfs(i, true);
        }
    }

    int l = 0, r = 0;
    for (const auto& colour : colours) {
        if (colour)
            l++;
        else
            r++;
    }

    cout << (l * r) - adj.size() + 1 << '\n';

    return 0;
}
