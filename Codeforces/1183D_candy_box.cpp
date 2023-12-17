// greedy - take the largest candy count first, and then second largest, so on...
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        int n;
        cin >> n;
        unordered_map<int, int> count;
        while(n--) {
            int a;
            cin >> a;
            count[a]++;
        }
        vector<int> orderedCounts;
        for (const auto& [k, v] : count) {
            orderedCounts.push_back(v);
        }
        sort(orderedCounts.rbegin(), orderedCounts.rend());

        int size = 0;
        int currCount = 0;
        for (int i = 0; i < orderedCounts.size(); i++) {
            if (i == 0) {
                size += orderedCounts[i];
                currCount = orderedCounts[i];
                continue;
            }
            if (currCount == 1) break;
            if (orderedCounts[i] >= currCount) {
                currCount--;
                size += currCount;
            } else if (orderedCounts[i] < currCount) {
                size += orderedCounts[i];
                currCount = orderedCounts[i];
            }
        }
        cout << size << '\n';
    }

    return 0;
}
