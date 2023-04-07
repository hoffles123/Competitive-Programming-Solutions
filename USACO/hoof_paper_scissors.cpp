/*
 * Maintain a prefix sum of all gestures
 * Go through each iteration and add the max gesture on left, and max gesture on right which is not the same gesture
 */

#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("hps.in", "r", stdin); \
    freopen("hps.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<unordered_map<char, int>> gestures(N);
    unordered_map<char, int> curr;
    for (int i = 0; i < N; i++) {
        char gesture;
        cin >> gesture;
        curr[gesture]++;
        gestures[i] = curr;
    }

    int maxWin = 0;
    for (int i = 0; i < N - 1; i++) {
        bool H = false, P = false, S = false;
        int HCount = gestures[i]['H'];
        int PCount = gestures[i]['P'];
        int SCount = gestures[i]['S'];
        if (HCount >= PCount && HCount >= SCount) {
            H = true;
        } else if (PCount >= HCount && PCount >= SCount) {
            P = true;
        } else if (SCount >= HCount && SCount >= PCount) {
            S = true;
        }

        if (H) {
            maxWin = max(maxWin, HCount + max(gestures[N - 1]['P'] - gestures[i]['P'], gestures[N-1]['S'] - gestures[i]['S']));
        } else if (P) {
            maxWin = max(maxWin, PCount + max(gestures[N - 1]['H'] - gestures[i]['H'], gestures[N-1]['S'] - gestures[i]['S']));
        } else if (S) {
            maxWin = max(maxWin, SCount + max(gestures[N - 1]['H'] - gestures[i]['H'], gestures[N-1]['P'] - gestures[i]['P']));
        }
    }

    cout << maxWin << '\n';

    return 0;
}
