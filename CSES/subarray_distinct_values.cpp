/*
 * sliding window
 * grow window as long as distinct values <= k
 * when distinct > k, each time you shrink array, add length of subarray [l, r)
 * this adds the number of subarrays starting from l
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ll = long long;

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    unordered_map<int, int> count;
    ll left = 0;
    ll right = 1;
    count[arr[left]]++;
    ll num = 0;
    while(right < n) {
        count[arr[right]]++;
        while(count.size() > k) {
            num += right - left;
            count[arr[left]]--;
            if (count[arr[left]] == 0)
                count.erase(arr[left]);
            left++;
        }
        right++;
    }

    // remaining is a AP sum
    ll remaining = right - left;
    num += remaining * (remaining + 1) / 2;

    cout << num << '\n';

    return 0;
}
