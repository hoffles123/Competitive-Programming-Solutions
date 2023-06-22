// coordinate compression + prefix sums
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // enumerate all timings in one array
    vector<int> arr(2*n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arr[2*i] = a;
        arr[2*i+1] = b;
    }

    // coordinate compression on timings to optimise space
    auto compression = arr;
    sort(compression.begin(), compression.end());
    unordered_map<int, int> compressionMap;
    for (int i = 0; i < compression.size(); i++) {
        compressionMap[compression[i]] = i;
    }

    vector<int> prefixArr(2*n);
    for (int i = 0; i < arr.size(); i++) {
        if (i % 2 == 0) {
            // even indexes are arrival timings
            prefixArr[compressionMap[arr[i]]]++;
        } else {
            // odd are leaving timings
            prefixArr[compressionMap[arr[i]]]--;
        }
    }

    // max prefix sum is the answer
    int prefixSum = prefixArr[0];
    int maxCustomer = prefixSum;
    for (int i = 1; i < prefixArr.size(); i++) {
        prefixSum += prefixArr[i];
        maxCustomer = max(maxCustomer, prefixSum);
    }

    cout << maxCustomer << '\n';

    return 0;
}
