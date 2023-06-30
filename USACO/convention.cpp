// not complete
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

bool canTransportAll(vector<int>& arr, int buses, int cap, int waiting) {
    int busCount = 0;
    int idx = 0;
    int firstTime = 0;
    int currCap = 0;
    while (idx < arr.size()) {
        if (firstTime == 0) {
            // first cow for next bus
            firstTime = arr[idx];
            currCap = 1;
        } else {
            // waiting too long, use next bus
            if (arr[idx] - firstTime > waiting) {
                firstTime = arr[idx];
                currCap = 0;
                busCount++;
            } else {
                currCap++;
            }
        }

        // if bus capacity reached, use next bus
        if (currCap == cap) {
            firstTime = 0;
            currCap = 0;
            busCount++;
        }

        idx++;
    }
    if (firstTime != 0) {
        busCount++;
    }
    return busCount <= buses;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, C;
    cin >> N >> M >> C;
    vector<int> arrival(N);
    int maxArrival = 0;
    for (int i = 0; i < N; i++) {
        cin >> arrival[i];
        maxArrival = max(maxArrival, arrival[i]);
    }

    sort(arrival.begin(), arrival.end());

    int left = 0;
    int right = maxArrival;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (canTransportAll(arrival, M, C, mid)) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << left << "\n";

    return 0;
}
