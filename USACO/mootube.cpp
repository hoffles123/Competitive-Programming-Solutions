/*
 * Graph is a tree as N nodes, N-1 edges
 * first build adj list of tree
 * for each question Q, root tree based on v
 * dfs down and simply count number of nodes reachable with K relevance
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("mootube.in", "r", stdin); \
    freopen("mootube.out", "w", stdout);

vector<vector<pair<int, int>>> adj;

void dfs(int node, int k, int& canReach, int parent) {
    if (parent != -1) canReach++;
    for (const auto& [child, relevance] : adj[node]) {
        if (child != parent && relevance >= k) {
            dfs(child, k, canReach, node);
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    adj.resize(N);
    for (int i = 0; i < N - 1; i++) {
        int p, q, r;
        cin >> p >> q >> r;
        p--, q--;
        // bidirectional
        adj[p].emplace_back(q, r);
        adj[q].emplace_back(p, r);
    }
    while(Q--) {
        int k, v;
        cin >> k >> v;
        v--;
        int canReach = 0;
        dfs(v, k, canReach, -1);
        cout << canReach << '\n';
    }

    return 0;
}
