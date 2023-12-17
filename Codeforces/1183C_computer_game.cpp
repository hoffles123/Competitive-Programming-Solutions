/*
 * n * b >= k , not possible, return 1
 * binary search the answer of max num of 1st type plays
 * no. of 1st type plays is monotonic search space from 0 to n
 * keep track of maximum
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

bool valid(ll k, ll n, ll a, ll b, ll firstPlays) {
    return k - (firstPlays * a) - ((n - firstPlays) * b) > 0;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        ll k, n, a, b;
        cin >> k >> n >> a >> b;
        if (n * b >= k) {
            cout << -1 << '\n';
            continue;
        }

        ll left = 0;
        ll right = n;
        while(left <= right) {
            ll mid = left + (right - left) / 2;
            if (valid(k, n, a, b, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        cout << right << '\n';
    }

    return 0;
}
