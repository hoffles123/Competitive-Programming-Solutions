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

    int n, t;
    cin >> n >> t;
    vector<int> books(n);
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    int left = 0;
    int right = 0;
    int sum = books[left];
    int maxCount = 0;
    while(right < n) {
        if (sum <= t) {
            maxCount = max(maxCount, right - left + 1);
            right++;
            sum += books[right];
        } else {
            if (left == right) {
                left++; right++;
                if (right < n) sum = books[right];
            } else {
                sum -= books[left];
                left++;
            }
        }
    }

    cout << maxCount << '\n';

    return 0;
}
