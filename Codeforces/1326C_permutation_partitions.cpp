#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

const int MOD = 998244353;

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    ll sum = 0;
    int ans = 1;
    int previousIdx = -1;
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        if (p >= n - k + 1) {
            if (previousIdx != -1)
                ans = 1LL * ans * (i - previousIdx) % MOD;
            previousIdx = i;
            sum += p;
        }
    }

    cout << sum << " " << ans << '\n';

    return 0;
}
