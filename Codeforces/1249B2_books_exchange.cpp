/*
 *  notice that each node will be in some cycle (with other nodes or with itself)
 *  Dfs for each node and check length of cycle
 *  length of cycle = no. of days it takes for book to return back to original owner
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

void dfs(vector<vector<int>>& adj, vector<bool>& visited, vector<int>& nodesInCycle, int& dist, int i) {
    if (visited[i])
        return;
    visited[i] = true;
    nodesInCycle.push_back(i);
    dist++;
    for (const int& neighbour : adj[i]) {
        dfs(adj, visited, nodesInCycle, dist, neighbour);
    }
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            int p;
            cin >> p;
            p--;
            // directed graph
            adj[i].push_back(p);
        }

        vector<bool> visited(n);
        vector<int> cycleLength(n);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> nodesInCycle;
                int dist = 0;
                dfs(adj, visited, nodesInCycle, dist, i);
                for (const int& node : nodesInCycle) {
                    cycleLength[node] = dist;
                }
            }
        }

        for (const int& c : cycleLength) {
            cout << c << " ";
        }
        cout << '\n';
    }

    return 0;
}
