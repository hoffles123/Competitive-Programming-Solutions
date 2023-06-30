/*
 * Binary search on monotonic functions
 * montonic search space on time time taken
 * binary search to find minimum time taken to build atleast t products
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

bool valid(vector<int>& arr, ll time, ll t) {
    ll products = 0;
    for (const int& i : arr) {
        products += time / (ll) i;
    }
    return products >= t;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, t;
    cin >> n >> t;
    vector<int> productionTimes(n);
    int minTime = INT_MAX;
    for (int i = 0; i < n; i++) {
        cin >> productionTimes[i];
        minTime = min(minTime, productionTimes[i]);
    }

    ll left = 1, right = minTime * t;
    while(left <= right) {
        ll mid = (left + right) / 2;
        if (valid(productionTimes, mid, t)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << '\n';

    return 0;
}
