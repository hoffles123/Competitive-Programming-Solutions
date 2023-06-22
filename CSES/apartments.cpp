// greedy
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

    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> desiredSize(n);
    for (int i = 0; i < n; i++) {
        cin >> desiredSize[i];
    }
    vector<int> apartmentSize(m);
    for (int i = 0; i < m; i++) {
        cin >> apartmentSize[i];
    }

    sort(desiredSize.begin(), desiredSize.end());
    sort(apartmentSize.begin(), apartmentSize.end());

    int p1 = 0;
    int p2 = 0;
    int count = 0;
    while(p1 < n && p2 < m) {
        int size = apartmentSize[p2];
        if (desiredSize[p1] - k <= size && size <= desiredSize[p1] + k) {
            count++;
            p1++;
            p2++;
        } else if (size < desiredSize[p1] - k) {
            p2++;
        } else {
            p1++;
        }
    }

    cout << count << '\n';

    return 0;
}
