// greedy
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

    int n, x;
    cin >> n >> x;
    vector<ll> weights(n);
    for (int i = 0; i < n; i++) {
        cin >> weights[i];
    }

    sort(weights.begin(), weights.end());

    int l = 0;
    int r = n - 1;
    int count = 0;
    while(l <= r) {
        if (l == r) {
            count++;
            break;
        }
        if (weights[l] + weights[r] > x) {
            count++;
            r--;
        } else {
            count++;
            l++;
            r--;
        }
    }

    cout << count << '\n';

    return 0;
}
