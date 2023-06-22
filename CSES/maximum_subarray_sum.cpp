/*
 *
 */

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
    vector<ll> prefix(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        prefix[i] = sum;
    }

    ll maxSum = prefix[0];
    ll minPrefix = 0;

    for (int i = 0; i < n; i++) {
        maxSum = max(maxSum, prefix[i] - minPrefix);
        minPrefix = min(minPrefix, prefix[i]);
    }

    cout << maxSum << '\n';

    return 0;
}
