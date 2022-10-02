#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

// slide through array to see if can form same values as target
bool valid(vector<int>& a, int target) {
    int sum = 0;
    for (auto x : a) {
        sum += x;
        if (sum > target) return false;
        else if (sum == target) sum = 0;
    }
    if (sum != 0) return false;
    return true;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int N, sum = 0;
        cin >> N;
        vector<int> a(N);
        for (int i = 0; i < N; i++) {
            cin >> a[i];
            sum += a[i];
        }

        // i = number of periods left
        for (int i = N; i >= 1; i--) {
            if (sum % i == 0) {
                if (valid(a, sum / i)) {
                    cout << N - i << "\n";
                    break;
                }
            }
        }
    }

    return 0;
}