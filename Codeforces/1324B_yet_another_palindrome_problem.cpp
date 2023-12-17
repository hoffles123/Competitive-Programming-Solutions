/*
 * if any element appears >= 3 times, has palindrome
 * if any element appears 2 times and is not subsequent, has palindrome
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

bool hasPalindrome(vector<int>& nums) {
    unordered_map<int, vector<int>> counts;
    for (int i = 0; i < nums.size(); i++) {
        counts[nums[i]].push_back(i);
    }

    for (const auto& kv : counts) {
        if (kv.second.size() >= 3)
            return true;
        if (kv.second.size() == 2 && kv.second[1] > kv.second[0] + 1)
            return true;
    }
    return false;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) {
            cin >> nums[i];
        }

        if (hasPalindrome(nums)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
