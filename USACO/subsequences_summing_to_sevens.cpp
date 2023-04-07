/* Prefix State Map
 * prefixSum % 7 -> index
 * if prefixSum % 7 is seen before, sum of subarray [index in map, current index] is multiple of 7
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("div7.in", "r", stdin); \
    freopen("div7.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    unordered_map<int, int> seen{{0, -1}};

    int prefixMod7 = 0;
    int maxLength = 0;
    for (int i = 0; i < N; i++) {
        int id;
        cin >> id;
        prefixMod7 = (prefixMod7 + id) % 7;
        if (seen.count(prefixMod7)) {
            maxLength = max(maxLength, i - seen[prefixMod7]);
        } else {
            seen[prefixMod7] = i;
        }
    }

    cout << maxLength << '\n';

    return 0;
}
