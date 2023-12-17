/*
 * length of LIS and reconstructing LIS
 * slight variation where subsequence values must be consecutive
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

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> dp(n, 1);
    vector<int> prev(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        prev[i] = i;
    }

    int lastIdx = -1;
    int LISSize = 0;
    unordered_map<int, int> seen;
    for (int i = 0; i < n; i++) {
        if (seen.count(arr[i] - 1)) {
            dp[i] = dp[seen[arr[i] - 1]] + 1;
            prev[i] = seen[arr[i] - 1];
            if (dp[i] > LISSize) {
                LISSize = dp[i];
                lastIdx = i;
            }
        }
        seen[arr[i]] = i;
    }

    if (!LISSize) {
        cout << 1 << '\n';
        cout << 1 << '\n';
        return 0;
    }

    cout << LISSize << '\n';
    vector<int> result(LISSize);
    int idx = LISSize - 1;
    while(prev[lastIdx] != lastIdx) {
        result[idx] = lastIdx + 1;
        lastIdx = prev[lastIdx];
        idx--;
    }
    result[0] = lastIdx + 1;
    for (const int& i : result) {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}
