// dfs - graph should only have 1 middle and no corners
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

bool outOfBounds(int h, int w, int i, int j) {
    if (i < 0 || j < 0 || i >= h || j >= w)
        return true;
    return false;
}

bool isStar(vector<vector<char>>& grid, int i, int j) {
    return !outOfBounds(grid.size(), grid[0].size(), i, j) && grid[i][j] == '*';
}

void dfs(vector<vector<char>>& grid, vector<vector<bool>>& seen, int& middle, int& corners, int i, int j) {
    int n = grid.size();
    int m = grid[0].size();
    if (outOfBounds(n, m, i, j) || grid[i][j] == '.')
        return;
    if (seen[i][j])
        return;

    seen[i][j] = true;

    if (isStar(grid, i + 1, j) &&
            isStar(grid, i - 1, j) &&
            isStar(grid, i, j + 1) &&
            isStar(grid, i, j - 1)) {
        middle++;
    } else {
        if ((isStar(grid, i + 1, j) && isStar(grid, i, j + 1)) ||
                (isStar(grid, i + 1, j) && isStar(grid, i, j - 1)) ||
                (isStar(grid, i, j - 1) && isStar(grid, i - 1, j)) ||
                (isStar(grid, i - 1, j) && isStar(grid, i, j + 1))) {
            corners++;
        }
    }

    dfs(grid, seen, middle, corners, i + 1, j);
    dfs(grid, seen, middle, corners, i - 1, j);
    dfs(grid, seen, middle, corners, i, j + 1);
    dfs(grid, seen, middle, corners, i, j - 1);
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int h, w;
    cin >> h >> w;
    vector<vector<char>> grid(h, vector<char>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<bool>> seen(h, vector<bool>(w));
    int middle = 0;
    int corners = 0;
    for (int i = 0; i < h; i++) {
        bool found = false;
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '*') {
                dfs(grid, seen, middle, corners, i, j);
                found = true;
                break;
            }
        }
        if (found) break;
    }

    if (middle != 1 || corners > 0) {
        cout << "NO" << '\n';
        return 0;
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == '*' && !seen[i][j]) {
                cout << "NO" << '\n';
                return 0;
            }
        }
    }

    cout << "YES" << '\n';

    return 0;
}
