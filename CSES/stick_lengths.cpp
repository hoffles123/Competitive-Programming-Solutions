// greedy - median
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
    vector<ll> lengths(n);
    for (size_t i = 0; i < lengths.size(); i++) {
        cin >> lengths[i];
    }

    sort(lengths.begin(), lengths.end());

    int mid = n / 2;
    ll cost = 0;
    for (ll &length : lengths) {
        cost += abs(lengths[mid] - length);
    }

    cout << cost << "\n";

    return 0;
}
