/*
dp[i][j] = number of paths to reach grid[i][j]

dp[i][j] = sum of number of paths from above or to the right
		 = dp[i - 1][j] + dp[i][j - 1]
dp[i][j] = '*' -> dp[i][j] = 0 (is a blockage)

Base cases
    dp[0]0] = 1 if grid[0][0] != *
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

const int MOD = 1e9 + 7;

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> grid[i][j];
        }
    }
    vector<vector<ll>> dp(n, vector<ll>(n));
    if (grid[0][0] != '*') dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '*') continue;
            if (i > 0) dp[i][j] += dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i][j - 1];
            dp[i][j] %= MOD;
        }
    }

    cout << dp[n - 1][n - 1] << '\n';

    return 0;
}
