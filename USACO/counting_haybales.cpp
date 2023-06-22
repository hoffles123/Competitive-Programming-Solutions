#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("haybales.in", "r", stdin); \
    freopen("haybales.out", "w", stdout);

int lowerBound(vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;
    int ans = arr.size();
    while(left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] >= target) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return ans;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<int> hays(N);
    for (int i = 0; i < N; i++) {
        cin >> hays[i];
    }

    sort(hays.begin(), hays.end());

    while(Q--) {
        int A, B;
        cin >> A >> B;
        int a = lowerBound(hays, A);
        int b = lowerBound(hays, B);
        if (a == hays.size()) {
            cout << 0 << "\n";
            continue;
        }
        if (b == hays.size() || hays[b] > B) b--;
        cout << b - a + 1 << "\n";
    }

    return 0;
}
