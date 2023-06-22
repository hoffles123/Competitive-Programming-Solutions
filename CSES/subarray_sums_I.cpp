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

    ll n, x;
    cin >> n >> x;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int l = 0;
    int r = 0;
    ll sum = arr[0];
    ll count = 0;
    while(r < n) {
        if (sum == x) {
            count++;
            if (l == r) {
                r++;
                sum += arr[r];
            } else {
                sum -= arr[l];
                l++;
            }
        } else if (sum < x) {
            r++;
            sum += arr[r];
        } else if (sum > x) {
            if (l == r) {
                r++;
                sum += arr[r];
            } else {
                sum -= arr[l];
                l++;
            }
        }
    }

    cout << count <<'\n';

    return 0;
}
