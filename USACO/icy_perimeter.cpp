/*
 * graph - connected components
 * perimeter for 1 node = surrounding . or out of bound edges
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("perimeter.in", "r", stdin); \
    freopen("perimeter.out", "w", stdout);

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int r, int c, int& area, int& peri) {
    visited[r][c] = true;
    area++;

    for (auto & d : dir) {
        int r1 = r + d[0];
        int c1 = c + d[1];
        // out of bounds
        if (r1 < 0 || c1 < 0 || r1 >= grid.size() || c1 >= grid[0].size()) {
            peri++;
            continue;
        }
        // empty space
        if (grid[r1][c1] == '.') {
            peri++;
            continue;
        }
        if (!visited[r1][c1]) {
            dfs(grid, visited, r1, c1, area, peri);
        }
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<vector<char>> grid(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }

    int maxArea = 0;
    int maxAreaPeri = 0;
    vector<vector<bool>> visited(N, vector<bool>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '#' && !visited[i][j]) {
                int area = 0;
                int peri = 0;
                dfs(grid, visited, i, j, area, peri);
                if (maxArea < area) {
                    maxArea = area;
                    maxAreaPeri = peri;
                } else if (maxArea == area) {
                    maxAreaPeri = peri;
                }
            }

        }
    }

    cout << maxArea << " " << maxAreaPeri << '\n';

    return 0;
}
