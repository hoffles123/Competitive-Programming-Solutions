// 3 sum
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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n - 2; i++) {
        int remainder = x - arr[i];
        unordered_map<int, int> seen; // val -> index
        for (int j = i + 1; j < n; j ++) {
            if (seen.count(remainder - arr[j])) {
                cout << i + 1 << " " << seen[remainder - arr[j]] + 1 << " " << j + 1 << '\n';
                return 0;
            }
            seen[arr[j]] = j;
        }
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
