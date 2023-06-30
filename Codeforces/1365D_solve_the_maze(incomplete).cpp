/*
 * (incomplete)
 * graph - connected components
 * Cases
 * no good ppl -> true (just block exit)
 * any good ppl already blocked -> false
 *
 * want all good ppl and exit to be in same connected component
 * bad ppl cannot be in above connected component
 * flood fill from all good ppl to see possible locations
 * if bad ppl is in same connected component, form wall around it
 * need to make sure good ppl can still reach exit after building walls
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int& count) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size())
        return;
    if (grid[r][c] == '#' || visited[r][c])
        return;

    visited[r][c] = true;
    if (grid[r][c] == 'G') count++;

    dfs(grid, visited, r + 1, c, count);
    dfs(grid, visited, r - 1, c, count);
    dfs(grid, visited, r, c + 1, count);
    dfs(grid, visited, r, c - 1, count);
}

bool solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<pair<int, int>> good;
    vector<pair<int, int>> bad;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'G') good.emplace_back(i, j);
            if (grid[i][j] == 'B') bad.emplace_back(i, j);
        }
    }

    if (good.empty()) return true;

    // search from exit if can reach all good
    vector<vector<bool>> visited(n, vector<bool>(m));
    int count = 0;
    dfs(grid, visited, n - 1, m - 1, count);
    if (count != good.size()) return false;

    // check all bad, build wall around if connected to good
    for (const auto& [r, c] : bad) {
        for (const auto& d : dir) {
            int r1 = r + d[0];
            int c1 = c + d[1];
            if (r1 < 0 || c1 < 0 || r1 >= grid.size() || c1 >= grid.size()) continue;
            if (grid[r1][c1] == 'B' || grid[r1][c1] == 'G' || grid[r1][c1] == '#') continue;
            if (visited[r1][c1]) grid[r1][c1] = '#';
        }
    }

    // search from exit if can reach all good
    vector<vector<bool>> visited1(n, vector<bool>(m));
    int count1 = 0;
    dfs(grid, visited1, n - 1, m - 1, count1);
    if (count1 != good.size()) return false;

    return true;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        if (solve())
            cout << "Yes" << '\n';
        else
            cout << "No" << "\n";
    }

    return 0;
}


