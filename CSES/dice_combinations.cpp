/*
 * knapsack dp
 * dp[i][j] = no. of ways to make up j with nums 1 ... i
 * if j < i
 *      dp[i][j] = dp[i - 1][j]
 * else
 *      dp[i][j] = sum of all dp[i][j - i], where i is 1...i;
 * Base case
 *      dp[i][0] = 1, 1 way to may up sum 0
 * bottom up dp, optimised space
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

    ll n;
    cin >> n;
    vector<ll> dp(n + 1);
    dp[0] = 1;
    for (int i = 1; i <= 6; i++) {
        for (int j = i; j <= n; j++) {
            dp[j] = 0;
            for (int k = 1; k <= i; k++) {
                dp[j] += dp[j - k];
                dp[j] %= MOD;
            }
        }
    }

    cout << dp[n] << '\n';

    return 0;
}
