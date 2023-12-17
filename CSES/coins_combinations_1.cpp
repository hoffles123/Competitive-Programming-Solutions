/*
 * dp[i] = number of permutations to make up amount i with the coins
 * dp[i] = sum of (dp[i - coin[j]) where j is iteration of all coins
 * if coin[j] > i, dp[i] = 0;
 *
 * dp[0] = 1 (1 way to make 1 amount)
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
    for (int i = 1; i <= x; i++) {
        for (const int& coin : coins) {
            if (coin > i) continue;
            dp[i] += dp[i - coin];
            dp[i] %= MOD;
        }
    }

    cout << dp[x] << '\n';

    return 0;
}
