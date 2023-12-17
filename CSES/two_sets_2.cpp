/*
 * 0/1 knapsack count combinations
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

    int n;
    cin >> n;
    int sum = n * (n + 1) / 2;
    if (sum % 2) {
        cout << 0 << '\n';
        return 0;
    }

    int target = sum / 2;
    vector<int> prev(target + 1);
    vector<int> curr(target + 1);
    prev[0] = 1;
    curr[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j <= target; j++) {
            if (i > j)
                curr[j] = prev[j];
            else {
                curr[j] = prev[j] + prev[j - i];
                curr[j] %= MOD;
            }
        }
        for (int col = 0; col < prev.size(); col++) {
            prev[col] = curr[col];
        }
    }

    cout << curr[target]  << '\n';

    return 0;
}
