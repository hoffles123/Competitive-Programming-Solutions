/*
 * dp[i][j] = number of combinations to make up amount j with 1...i coins
 * if j < coins[i]
 *      dp[i][j] = dp[i - 1][j] (cannot use coin)
 * else
 *      dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i]
 * base case
 *      when j = 0, dp[i][j] = 1
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

const int MOD = 1e9 + 7;

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    vector<int> dp(x + 1);
    dp[0] = 1;
    for (const int& coin : coins) {
        for (int j = 1; j <= x; j++) {
            if (coin > j) continue;
            dp[j] += dp[j - coin];
            dp[j] %= MOD;
        }
    }

    cout << dp[x] << '\n';

    return 0;
}
