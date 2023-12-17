// sliding window
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
    unordered_set<int> seen;
    int left = 0;
    int right = 1;
    int maxWindow = 1;
    seen.insert(arr[left]);
    while(right < n) {
        while(left <= right && seen.count(arr[right])) {
            seen.erase(arr[left]);
            left++;
        }
        seen.insert(arr[right]);
        maxWindow = max(maxWindow, right - left + 1);
        right++;
    }

    cout << maxWindow << '\n';

    return 0;
}
