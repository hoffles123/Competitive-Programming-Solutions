#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("circlecross.in", "r", stdin); \
    freopen("circlecross.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // save crossing points of all cows
    int paths[26][2] = {};
    char cow;
    for (int i = 1; i <= 52; i++) {
        cin >> cow;
        if (paths[cow - 'A'][0] == 0) {
            paths[cow - 'A'][0] = i;
        } else {
            paths[cow - 'A'][1] = i;
        }
    }

    // will only have intersection in 2 scenarios ABAB, BABA
    int count = 0;
    for (int i = 0; i < 25; i++) {
        for (int j = i + 1; j < 26; j++) {
            if ((paths[i][0] < paths[j][0] && paths[j][0] < paths[i][1] && paths[i][1] < paths[j][1]) ||
                    (paths[j][0] < paths[i][0] && paths[i][0] < paths[j][1] && paths[j][1] < paths[i][1]))
                count++;
        }
    }
    cout << count << endl;

    return 0;
}