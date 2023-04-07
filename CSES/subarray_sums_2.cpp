/*
 * Prefix State map
 * Maintain prefix sum, if prefix Sum - x is in map, subarray has sum of x
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
    unordered_map<long long, long long> seen{{0, 1}};
    long long sum = 0;
    long long count = 0;
    while(n--) {
        int i;
        cin >> i;
        sum += i;
        if (seen.count(sum - x))
            count += seen[sum-x];
        seen[sum]++;
    }

    cout << count << '\n';

    return 0;
}
