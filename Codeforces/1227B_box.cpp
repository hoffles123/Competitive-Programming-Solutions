/*
 * maintain a used[] bool array, whenever q == q-1, search smallest in q array which is not used yet
 */
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
        int n;
        cin >> n;
        vector<bool> used(n, false);
        vector<int> q(n);
        for (int i = 0; i < n; i++) {
            cin >> q[i];
        }
        int usedIdx = 0;
        vector<int> result;
        bool valid = true;
        for (int i = 0; i < n; i++) {
            if (i == 0 || q[i] != q[i - 1]) {
                int num = q[i];
                used[num - 1] = true;
                result.push_back(num);
            } else {
                while(usedIdx < q[i] && used[usedIdx]) {
                    usedIdx++;
                }
                if (usedIdx == q[i]) {
                    valid = false;
                    break;
                }
                used[usedIdx] = true;
                result.push_back(usedIdx + 1);
            }
        }
        if (!valid) {
            cout << -1 << '\n';
            continue;
        }
        for (int i = 0; i < n; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
    }

    return 0;
}
