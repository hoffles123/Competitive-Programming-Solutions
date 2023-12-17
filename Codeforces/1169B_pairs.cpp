#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

struct node {
    int size{};
    unordered_map<int, int> neighbours; // neighbour num -> count
};

bool solve() {
    int n, m;
    cin >> n >> m;
    unordered_map<int, node> nodes;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        nodes[a].size++;
        nodes[a].neighbours[b]++;
        nodes[b].size++;
        nodes[b].neighbours[a]++;
    }

    unordered_map<int, vector<int>> sizes;
    for (const auto& [num, node] : nodes) {
        sizes[node.size].push_back(num);
    }

    for (const auto& [num, node] : nodes) {
        if (node.size == m) {
            return true;
        }
        // check corresponding m - size nodes
        for (const int& candidate : sizes[m - node.size]) {
            if (candidate == num)
                continue;
            if (node.size + nodes[candidate].size - nodes[candidate].neighbours[num] == m)
                return true;
        }
    }
    return false;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    if (solve()) {
        cout << "YES" << '\n';
    } else {
        cout << "NO" << '\n';
    }

    return 0;
}
