// two sum
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

#define ll long long

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    unordered_map<int, int> want;
    int index = 1;
    while(n--) {
        int i;
        cin >> i;

        if (want.count(i)) {
            cout << want[i] << " " << index << "\n";
            return 0;
        }

        if (i < x) {
            want[x - i] = index;
        }

        index++;
    }

    cout << "IMPOSSIBLE" << '\n';

    return 0;
}
