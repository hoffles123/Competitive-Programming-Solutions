// monotonic stack (nearest smallest) + binary search

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
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> nearestSmallestIdx(n);
    stack<pair<int, int>> s; // monotonic increasing
    for (int i = 0; i < n; i++) {
        while(!s.empty() && s.top().first >= arr[i]) {
            s.pop();
        }
        nearestSmallestIdx[i] = s.empty() ? 0 : s.top().second;
        s.emplace(arr[i], i + 1);
    }

    vector<pair<int, int>> heightWidthUsed(n);
    ll maxArea = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(nearestSmallestIdx.begin(), nearestSmallestIdx.end(), nearestSmallestIdx[i]);
        if (nearestSmallestIdx[i] == 0) {
            ll currArea = arr[i] * (i - *it + 1);
            if (maxArea < currArea)
                maxArea = currArea;
            heightWidthUsed[i] = {arr[i], (i - *it + 1)};
        } else {
            ll useSelfHeight = arr[i] * (i - *it + 1);
            ll useNearestSmallestHeight = heightWidthUsed[nearestSmallestIdx[i]].first * (heightWidthUsed[nearestSmallestIdx[i]].second + 1);
            if (useSelfHeight > useNearestSmallestHeight) {
                heightWidthUsed[i] = {arr[i], (i - *it + 1)};
                if (maxArea < useSelfHeight)
                    maxArea = useSelfHeight;
            } else {
                heightWidthUsed[i] = {heightWidthUsed[nearestSmallestIdx[i]].first, heightWidthUsed[nearestSmallestIdx[i]].second + 1};
                if (maxArea < useNearestSmallestHeight)
                    maxArea = useNearestSmallestHeight;
            }
        }
    }

    cout << maxArea << '\n';

    return 0;
}
