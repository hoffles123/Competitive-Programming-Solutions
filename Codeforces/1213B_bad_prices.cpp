/*
 * montonic stack
 * traverse from right to left and maintain monotonic decreasing stack
 * everytime element is bigger than top, its a bad day
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int count = 0;
        stack<int> s;
        for (int i = n - 1; i >= 0; i--) {
            if (!s.empty() && s.top() < arr[i]) {
                count++;
                continue;
            }
            s.push(arr[i]);
        }
        cout << count << '\n';
    }

    return 0;
}
