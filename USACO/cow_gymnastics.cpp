/*
 * Time: O(N^2 * K)
 * Space: O(N * K)
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("gymnastics.in", "r", stdin); \
    freopen("gymnastics.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, N;
    cin >> K >> N;
    vector<vector<int>> ranking(N, vector<int>(K));
    // save rankings in grid
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N; j++) {
            int cow;
            cin >> cow;
            ranking[cow - 1][i] = j;
        }
    }

    int count = 0;
    // iterate through all distinct pairs
    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            // if pair consistent in ranking, add to count
            bool isBigger = true;
            if (ranking[i][0] < ranking[j][0]) isBigger = false;
            int k;
            for (k = 1; k < K; k++) {
                if (ranking[i][k] < ranking[j][k] && isBigger) break;
                if (ranking[i][k] > ranking[j][k] && !isBigger) break;
            }
            if (k == K) count++;
        }
    }
    cout << count << endl;

    return 0;
}