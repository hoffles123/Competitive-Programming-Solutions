// graphs - connected components
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

void dfs(vector<vector<char>>& map, int r, int c) {
    if (r < 0 || c < 0 || r >= map.size() || c >= map[0].size())
        return;
    if (map[r][c] == '#')
        return;
    map[r][c] = '#';
    dfs(map, r - 1, c);
    dfs(map, r + 1, c);
    dfs(map, r, c  - 1);
    dfs(map, r, c + 1);
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (map[i][j] == '.') {
                dfs(map, i, j);
                count++;
            }
        }
    }

    cout << count << '\n';

    return 0;
}
