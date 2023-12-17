#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> coins(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
        sum += coins[i];
    }
    vector<int> prev(sum + 1);
    vector<int> curr(sum + 1);
    prev[0] = 1;
    curr[0] = 1;

    int currSum = 0;
    int count = 0;
    for (const int& coin : coins) {
        currSum += coin;
        for (int j = 1; j <= currSum; j++) {
            if (coin > j) {
                curr[j] = prev[j];
            } else {
                if (!prev[j] && prev[j - coin])
                    count++;
                curr[j] = prev[j] || prev[j - coin];
            }
        }
        for (int col = 0; col <= currSum; col++) {
            prev[col] = curr[col];
        }
    }

    cout << count << '\n';
    for (int j = 1; j <= sum; j++) {
        if (curr[j]) cout << j << " ";
    }
    cout << '\n';

    return 0;
}
