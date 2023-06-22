// greedy - interval scheduling
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ii = pair<int, int>;

bool comp(const ii &a, const ii &b) {
    return a.second < b.second;
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<ii> movies(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies[i] = {a, b};
    }

    sort(movies.begin(), movies.end(), comp);

    int count = 0;
    int currEnd = 0;
    for (auto &m : movies) {
        if (currEnd <= m.first) {
            count++;
            currEnd = m.second;
        }
    }

    cout << count << "\n";

    return 0;
}
