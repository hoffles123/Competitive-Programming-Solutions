// bfs - shortest path unweighted graph with distance and path reconstruction
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char dirA[4] = {'D', 'R', 'U', 'L'};

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    pair<int, int> A, B;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                A = {i, j};
            else if (grid[i][j] == 'B')
                B = {i, j};
        }
    }

    queue<pair<int, int>> q;
    q.push(A);
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    visited[A.first][A.second] = true;
    vector<vector<char>> origin(n, vector<char>(m, 'O'));
    while(!q.empty()) {
        const auto& [x, y] = q.front();
        q.pop();
        for (int d = 0; d < 4; d++) {
            int x1 = x + dir[d][0];
            int y1 = y + dir[d][1];
            if (x1 < 0 || y1 < 0 || x1 >= n || y1 >= m || visited[x1][y1] || grid[x1][y1] == '#')
                continue;
            visited[x1][y1] = true;
            origin[x1][y1] = dirA[d];
            q.emplace(x1, y1);
        }
    }

    if (origin[B.first][B.second] == 'O') {
        cout << "NO" << '\n';
        return 0;
    }

    cout << "YES" << '\n';
    vector<char> path;
    pair<int, int> node = B;
    while(origin[node.first][node.second] != 'O') {
        char c = origin[node.first][node.second];
        path.emplace_back(c);
        switch (c){
            case 'L':
                node.second++;
                break;
            case 'R':
                node.second--;
                break;
            case 'U':
                node.first++;
                break;
            case 'D':
                node.first--;
                break;
        }
    }

    cout << path.size() << '\n';
    for (int i = path.size() - 1; i >= 0; i--) {
        cout << path[i];
    }
    cout << '\n';

    return 0;
}
