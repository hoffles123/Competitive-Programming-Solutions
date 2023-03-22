// check every interval, return smallest interval where every interval of that size is unique
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

#define ll long long

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string colors;
    cin >> N >> colors;

    for (int interval = 1; interval < N; interval++) {
        unordered_set<string> seen;
        bool valid = true;
        for (int l = 0; l < N - interval; l++) {
            int r = l + interval;
            string s{};
            for (int i = l; i <= r; i++) {
                s += colors[i];
            }
            if (seen.count(s)) {
                valid = false;
                break;
            }
            seen.insert(s);
        }

        if (valid) {
            cout << interval + 1 << '\n';
            return 0;
        }
    }

    cout << N << '\n';

    return 0;
}
