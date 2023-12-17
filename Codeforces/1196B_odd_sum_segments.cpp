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
        int n, k;
        cin >> n >> k;
        vector<int> oddPositions;
        for (int i = 0; i < n; i++) {
            int a;
            cin >> a;
            if (a % 2) {
                oddPositions.emplace_back(i + 1);
            }
        }
        if (oddPositions.size() < k) {
            cout << "NO" << '\n';
            continue;
        }
        if (oddPositions.size() % 2 != k % 2) {
            cout << "NO" << '\n';
            continue;
        }
        cout << "YES" << '\n';
        for (int i = 0; i < k - 1; i++) {
            cout << oddPositions[i] << " ";
        }
        cout << n << '\n';
    }

    return 0;
}
