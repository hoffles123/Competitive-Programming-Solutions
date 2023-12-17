// monotonic stack
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    stack<pair<int, int>> s; // monotonic increasing
    vector<int> result(n);
    for (int i = 0; i < n; i++) {
        while(!s.empty() && s.top().first >= arr[i]) {
            s.pop();
        }
        result[i] = s.empty() ? 0 : s.top().second;
        s.emplace(arr[i], i + 1);
    }

    for (const int& i : result) {
        cout << i << " ";
    }
    cout << '\n';

    return 0;
}
