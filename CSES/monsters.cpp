/*
 * SSSP (single source shortest path) - bfs from A to find shortest path to all boundary squares
 * bfs from all M to find boundary shortest path of to all boundary squares
 * If A is able to reach boundary square before all M, path is possible
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ii = pair<int, int>;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char dirA[4] = {'D', 'R', 'U', 'L'};

vector<vector<char>> grid;

// A hash function used to hash a pair of any kind
struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);
        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }
        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

void bfs(unordered_map<ii, int, hash_pair>& dist, vector<vector<char>>& origin, pair<int, int> src) {
    vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size()));
    queue<tuple<int, int, int>> q;
    q.emplace(src.first, src.second, 0);
    visited[src.first][src.second] = true;
    while(!q.empty()) {
        const auto& [x, y, currDist] = q.front();
        q.pop();
        // if boundary, store dist
        if (x == 0 || y == 0 || x == grid.size() - 1 || y == grid[0].size() - 1) {
            dist[{x, y}] = currDist;
        }
        for (int d = 0; d < 4; d++) {
            int x1 = x + dir[d][0];
            int y1 = y + dir[d][1];
            if (x1 < 0 || y1 < 0 || x1 >= grid.size() || y1 >= grid[0].size() || visited[x1][y1] || grid[x1][y1] == '#')
                continue;
            q.emplace(x1, y1, currDist + 1);
            visited[x1][y1] = true;
            origin[x1][y1] = dirA[d];
        }
    }
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    pair<int, int> A;
    vector<pair<int, int>> Ms;
    grid.resize(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
                A = {i, j};
            else if (grid[i][j] == 'M')
                Ms.emplace_back(i, j);
        }
    }

    unordered_map<ii, int, hash_pair> distA;
    vector<vector<char>> originA(n, vector<char>(m, 'O'));
    vector<unordered_map<ii, int, hash_pair>> distMs;
    vector<vector<char>> dummyOrigin(n, vector<char>(m));

    // bfs for A
    bfs(distA, originA, A);

    // bfs for all Ms
    for (const auto& M : Ms) {
        unordered_map<ii, int, hash_pair> distM;
        distM[M] = 0;
        bfs(distM, dummyOrigin, M);
        distMs.push_back(distM);
    }

    // check if A can reach any boundary before all Ms
    bool possible = false;
    ii possibleBoundary;
    for (const auto [boundary, dist] : distA) {
        bool foundM = false;
        for (const auto& mmap : distMs) {
            for (const auto [boundaryM, distM] : mmap) {
                if (boundaryM.first == boundary.first && boundary.second == boundaryM.second && distM <= dist)
                    foundM = true;
            }
        }
        if (!foundM) {
            possibleBoundary = boundary;
            possible = true;
            break;
        }
    }

    if (Ms.empty() && !distA.empty()) {
        possible = true;
        possibleBoundary = distA.begin()->first;
    }

    if (!possible) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
        //print path
        string path;
        ii node = possibleBoundary;
        while(originA[node.first][node.second] != 'O') {
            path += originA[node.first][node.second];
            switch (originA[node.first][node.second]) {
                case 'U':
                    node.first++;
                    break;
                case 'D':
                    node.first--;
                    break;
                case 'L':
                    node.second++;
                    break;
                case 'R':
                    node.second--;
                    break;
            }
        }
        cout << path.size() << '\n';
        reverse(path.begin(), path.end());
        cout << path << '\n';
    }

    return 0;
}
