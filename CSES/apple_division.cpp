/*
 * Generate subsets (using bitmasks) and calculate sum (this simulates possible weights for 1 group)
 * Find diff to and keep track of min for all possible weights
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

#define ll long long

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ll> apples(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> apples[i];
        sum += apples[i];
    }

    ll minDiff = 1e9 * 20;
    for (int b = 0; b < (1 << n); b++) {
        ll currSum = 0;
        for (int i = 0; i < n; i++) {
            if (b & (1 << i)) {
                currSum += apples[i];
            }
        }
        minDiff = min(minDiff, abs(sum - currSum - currSum));
    }

    cout << minDiff << endl;

    return 0;
}