/*
 * largest D = min distance between each cow
 * min distance between each cow is search space. lowest = 1, highest = max end of all intervals
 *
 * sort the intervals - by start as no overlaps
 *
 * binary search of all D
 *  smaller D = more valid
 *  larger D = less valid
 *
 *
 */
#include <bits/stdc++.h>

using namespace std;

using ll = long long;

#define IO \
    freopen("socdist.in", "r", stdin); \
    freopen("socdist.out", "w", stdout);

bool canPlace(vector<pair<ll, ll>>& intervals, int N, ll D) {
    int cowsPlaced = 1;
    int idx = 0;
    ll currLocation = intervals[0].first;
    while(currLocation + D <= intervals[intervals.size() - 1].second) {
        while(currLocation + D > intervals[idx].second) {
            idx++;
        }
        currLocation = max(intervals[idx].first, currLocation + D);
        cowsPlaced++;
        if (cowsPlaced == N) break;
    }
    return cowsPlaced >= N;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<ll, ll>> intervals(M);
    ll furthest = 0;
    for (int i = 0; i < M; i++) {
        ll a, b;
        cin >> a >> b;
        if (b > furthest) {
             furthest = b;
        }
        intervals[i] = {a, b};
    }

    sort(intervals.begin(), intervals.end());

    ll left = 1, right = furthest;
    while(left <= right) {
        ll mid = left + (right - left) / 2;
        if (canPlace(intervals, N, mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << right << '\n';

    return 0;
}
