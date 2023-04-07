/*
 * Prefix State map
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
    int prefixMod = 0;
    unordered_map<int, ll> seen{{0, 1}};

    ll count = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        prefixMod = (prefixMod + a) % n;
        if (prefixMod < 0) prefixMod += n;
        if (seen.count(prefixMod)) {
            count += seen[prefixMod];
        }
        seen[prefixMod]++;
    }

    cout << count << '\n';

    return 0;
}