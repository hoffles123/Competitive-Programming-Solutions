#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("tracing.in", "r", stdin); \
    freopen("tracing.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T;
    cin >> N >> T;
    vector<char> isSick(N);
    vector<vector<int>> logs(T, vector<int>(3));
    for (int i = 0; i < N; i++) {
        cin >> isSick[i];
    }
    for (int i = 0; i < T; i++) {
        cin >> logs[i][0] >> logs[i][1] >> logs[i][2];
        logs[i][1]--;
        logs[i][2]--;
    }
    // sort by time
    sort(logs.begin(), logs.end(), [](const vector<int>& x, const vector<int>& y) {
        return x[0] < y[0];
    });

    int minK = INT_MAX;
    int maxK = INT_MIN;
    int count = 0;
    // simulate each cow is patient zero
    for (int i = 0; i < N; i++) {
        vector<char> state(N, '0');
        state[i] = '1';
        int currMin = INT_MAX;
        int currMax = INT_MIN;
        for (int K = 0; K <= T + 1; K++) {
            vector<int> shakes(N);
            shakes[i] = K;
            for (auto& log : logs) {
                int x = log[1];
                int y = log[2];
                bool newY = false;
                if (shakes[x] > 0) {
                    shakes[x]--;
                    if (state[y] == '0') {
                        state[y] = '1';
                        shakes[y] = K;
                        newY = true;
                    }
                }
                if (shakes[y] > 0 && !newY) {
                    shakes[y]--;
                    if (state[x] == '0') {
                        state[x] = '1';
                        shakes[x] = K;
                    }
                }
            }
            if (state == isSick) {
                currMin = min(currMin, K);
                currMax = max(currMax, K);
            }
        }
        if (currMin != INT_MAX) {
            count++;
            minK = min(minK, currMin);
            if (currMax >= 0 && currMax <= T) {
                maxK = max(maxK, currMax);
            }
        }
    }
    string m = maxK == INT_MIN ? "Infinity" : to_string(maxK);
    cout << count << " " << minK << " " << m;

    return 0;
}