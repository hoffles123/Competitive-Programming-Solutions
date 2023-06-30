/*
 * graph + binary search
 * monotonic search space: D -> elevation of cell
 * binary search to find min D that is still able to travel all waypoints
 * larger D is valid, smaller D not valid
 *
 * For each D, try to dfs from one waypoint and see if it can reach all other waypoints
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("ccski.in", "r", stdin); \
    freopen("ccski.out", "w", stdout);

struct hashFunc {
    size_t operator()(const pair<int, int> &x) const {
        return x.first ^ x.second;
    }
};

vector<vector<int>> grid;
unordered_set<pair<int, int>, hashFunc> waypoints;

void dfs(vector<vector<bool>>& visited, int D, int& count, int r, int c, int prev) {
    if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size()) return;
    if (abs(prev - grid[r][c]) > D) return;
    if (visited[r][c]) return;
    if (waypoints.count({r, c})) count++;

    visited[r][c] = true;
    dfs(visited, D, count, r + 1, c, grid[r][c]);
    dfs(visited, D, count, r - 1, c, grid[r][c]);
    dfs(visited, D, count, r, c + 1, grid[r][c]);
    dfs(visited, D, count, r, c - 1, grid[r][c]);
}

bool valid(int D) {
    pair<int, int> startWaypoint = *waypoints.begin();
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    int count = 0;
    dfs(visited, D, count, startWaypoint.first, startWaypoint.second, grid[startWaypoint.first][startWaypoint.second]);
    return count == waypoints.size();
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;
    grid.resize(M, vector<int>(N));
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            int k;
            cin >> k;
            if (k == 1) waypoints.insert({i, j});
        }
    }

    int left = 0, right = 1e9;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (valid(mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << "\n";

    return 0;
}
