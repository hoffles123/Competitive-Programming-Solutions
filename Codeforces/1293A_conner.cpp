// simulate walking up or down k steps
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, s, k;
        cin >> n >> s >> k;
        unordered_set<int> closed;
        for (int i = 0; i < k; i++) {
            int a;
            cin >> a;
            closed.insert(a);
        }
        for (int i = 0; i <= k; i++) {
            int pos = s + i;
            if (pos >= 1 && pos <= n && !closed.count(pos)) {
                cout << i << '\n';
                break;
            }
            pos = s - i;
            if (pos >= 1 && pos <= n && !closed.count(pos)) {
                cout << i << '\n';
                break;
            }
        }
    }

    return 0;
}
