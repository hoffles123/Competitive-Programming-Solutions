// tree traversal - size of subtree
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

map<int, int> subordinates;

int dfs(int node, vector<vector<int>>& adj) {
    int numSubordinates = 0;
    for (const int& child : adj[node]) {
        numSubordinates += dfs(child, adj);
    }
    subordinates[node] = numSubordinates;
    return numSubordinates + 1;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> adj(n);
    n--;
    int node = 1;
    while(n--) {
        int parent;
        cin >> parent;
        parent--;
        adj[parent].push_back(node);
        node++;
    }

    dfs(0, adj);

    for (const auto& [employee, numSubordinates] : subordinates) {
        cout << numSubordinates << " ";
    }
    cout << '\n';

    return 0;
}
