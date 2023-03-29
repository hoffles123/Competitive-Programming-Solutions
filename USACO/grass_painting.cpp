/* let D be max degree of a node
 * answer is D + 1
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("planting.in", "r", stdin); \
    freopen("planting.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> degree(N + 1);
    int maxDegree = 0;
    for (int i = 0; i < N - 1; i++) {
        int x, y;
        cin >> x >> y;
        degree[x]++;
        degree[y]++;
        maxDegree = max({maxDegree, degree[x], degree[y]});
    }

    cout << maxDegree + 1 << '\n';

    return 0;
}
