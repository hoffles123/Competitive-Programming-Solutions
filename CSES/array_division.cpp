#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

bool valid(vector<int>& arr, int k, ll sum) {
    int count = 0;
    ll currSum = 0;
    for (const int& i : arr) {
        if (i > sum) return false;
        if (currSum + i > sum) {
            count++;
            currSum = 0;
        }
        currSum += i;
    }

    if (currSum <= sum) count++;

    return count <= k;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    ll left = 1, right = sum;
    while(left <= right) {
        ll mid = (left + right) / 2;
        if (valid(arr, k, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << '\n';

    return 0;
}
