/*
 * coin change
 * dp[i][j] = min coins needed to make up amount j, with coins 1...i
 * if j < coins[i]
 *      dp[i][j] = dp[i - 1][j] (cannot take coins i)
 * else
 *      dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i]] + 1)
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

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
    vector<int> dp(x + 1, x + 1);
    dp[0] = 0;
    for (const int& coin : coins) {
        for (int j = coin; j <= x; j++) {
            dp[j] = min(dp[j], dp[j - coin] + 1);
        }
    }

    int result = dp[x] > x ? -1 : dp[x];
    cout << result << '\n';

    return 0;
}
