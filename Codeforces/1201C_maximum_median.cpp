/*
 * Binary Search on function
 * possible medians is the monotonic search space
 * key insight: if we want to increase current median to x, have to increase all elements from middle to the end of arr
 * to atleast x. If all these operations > k, x as a median is invalid. vice versa
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

bool f(vector<int>& arr, int median, int k) {
    ll ops = 0;
    for (int i = arr.size() / 2; i < arr.size(); i++) {
        ops += max(0, median - arr[i]);
    }
    if (ops <= k) return true;
    return false;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    int left = arr[n/2];
    int right = left + k;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (f(arr, mid, k)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << "\n";

    return 0;
}
