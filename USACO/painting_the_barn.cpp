/*
 * Constructing 2D prefix sum
 * Read editorial for explanation
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> prefix(1001, vector<int>(1001, 0));

    int N, K;
    cin >> N >> K;
    while(N--) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        for (int x = x1; x < x2; x++) {
            prefix[x][y1]++;
            prefix[x][y2]--;
        }
    }

    int count = 0;
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++) {
            if (j) prefix[i][j] += prefix[i][j - 1];
            if (prefix[i][j] == K) count++;
        }
    }

    cout << count << '\n';

    return 0;
}
