/*
 For each node 1, it has to have atleast 3 adjacent 1's in the corners. If not it is impossible to make B = A
 Iterate through grid, check all 1s. mark it and any adjacent 3 1's as seen, take top left as representative and add to result
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int dir[8][2] = {
        {-1, 0},
        {-1, 1},
        {0, 1},
        {1, 1},
        {1, 0},
        {1, -1},
        {0, -1},
        {-1, -1}
};

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    vector<pair<int, int>> seq;
    bool valid = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '1') {
                vector<bool> adj(8);
                for (int d = 0; d < 8; d++) {
                    int x = i + dir[d][0];
                    int y = j + dir[d][1];
                    if (x < 0 || y < 0 || x >= n || y >= m) continue;
                    if (grid[x][y] == '1') {
                        adj[d] = true;
                    }
                }
                int possible =false;
                if ((adj[0] && adj[1] && adj[2]) ||
                        (adj[2] && adj[3] && adj[4]) ||
                        (adj[4] && adj[5] && adj[6]) ||
                        (adj[6] && adj[7] && adj[0])) {
                    possible = true;
                }
                if (!possible) {
                    valid = false;
                    break;
                }
                if (adj[0] && adj[1] && adj[2]) {
                    seq.emplace_back(i + dir[0][0], j + dir[0][1]);
                }
            }
        }
        if (!valid) break;
    }

    if (!valid) {
        cout << -1 << '\n';
    } else {
        cout << seq.size() << '\n';
        for (const auto& [x, y] : seq) {
            cout << x + 1 << " " << y + 1 << '\n';
        }
    }

    return 0;
}
