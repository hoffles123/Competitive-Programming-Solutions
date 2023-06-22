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
    vector<int> towers;
    while(n--) {
        int k;
        cin >> k;
        if (towers.empty()) {
            towers.push_back(k);
        } else {
            auto it = lower_bound(towers.begin(), towers.end(), k);
            if (it == towers.end()) {
                towers.push_back(k);
            } else if (towers[it - towers.begin()] == k) {
                auto it2 = upper_bound(it, towers.end(), k);
                if (it2 == towers.end()) {
                    towers.push_back(k);
                } else {
                    towers[it2 - towers.begin()] = k;
                }
            } else {
                towers[it - towers.begin()] = k;
            }
        }
    }

    cout << towers.size() << "\n";

    return 0;
}
