/*
 * 0/1 knapsack, same as finding max value of items
 * dp[i][j] = max pages achievable for j price and 1...i books
 * if price[i] > j
 *      dp[i][j] = dp[i - 1][j] (skip book)
 *  else
 *      dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - price[i] + pages[i])
 *
 *  base case
 *      i == 0, dp[i][j] = 0
 *      j == 0, dp[i][j] = 0,
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
    vector<int> prices(n);
    vector<int> pages(n);
    for (int i = 0; i < n; i++) {
        cin >> prices[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }
    vector<int> prev(x + 1);
    vector<int> curr(x + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= x; j++) {
            if (prices[i - 1] > j) {
                curr[j] = prev[j];
            } else {
                curr[j] = max(prev[j], prev[j - prices[i - 1]] + pages[i - 1]);
            }
        }
        for (int col = 0; col < prev.size(); col++) {
            prev[col] = curr[col];
        }
    }

    cout << curr[x] << '\n';

    return 0;
}
