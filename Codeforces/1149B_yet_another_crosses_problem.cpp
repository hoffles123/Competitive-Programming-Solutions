#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        vector<int> rows(n);
        for (int i = 0; i < n; i++) {
            int row = 0;
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '*') row++;
            }
            rows[i] = row;
        }
        vector<int> cols(m);
        for (int j = 0; j < m; j++) {
            int col = 0;
            for (int i = 0; i < n; i++) {
                if (grid[i][j] == '*') col++;
            }
            cols[j] = col;
        }

        int minAdd = n * m;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '.') {
                    minAdd = min(minAdd, m - rows[i] + n - cols[j] - 1);
                } else {
                    minAdd = min(minAdd, m - rows[i] + n - cols[j]);
                }
            }
        }
        cout << minAdd << '\n';
    }

    return 0;
}
