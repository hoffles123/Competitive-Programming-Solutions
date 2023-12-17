/*
 * number of candies eaten (x) is between 0 and n-1
 * we can binary search on this monotonic search space
 * if x is too small, we will have left over too many candies. vice versa
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

bool tooSmall(int x, int n, int k) {
    ll sum = 0;
    ll counter = 1;
    for (int i = 0; i < n - x; i++) {
        sum += counter;
        counter++;
    }
    return sum - x >= k;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int left = 0;
    int right = n - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (tooSmall(mid, n, k)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << '\n';

    return 0;
}
