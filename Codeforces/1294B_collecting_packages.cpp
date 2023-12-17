/*
 * sort packages by their distance from origin
 * if have to travel left or down from previous package, route is not possible
 * if possible, print the route
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

using ii = pair<int, int>;

int distance(int x, int y) {
    return x + y;
}

bool comp(const ii& p1, const ii& p2) {
    return distance(p1.first, p1.second) < distance(p2.first, p2.second);
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
        vector<ii> packages(n);
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            packages[i] = {x, y};
        }

        sort(packages.begin(), packages.end(), comp);

        string path;
        bool valid = true;
        ii currLoc = {0, 0};
        for (int i = 0; i < n; i++) {
            if (i > 0 && (packages[i - 1].first > packages[i].first || packages[i - 1].second > packages[i].second)) {
                valid = false;
                break;
            }
            for (int j = 0; j < packages[i].first - currLoc.first; j++) {
                path += 'R';
            }
            for (int j = 0; j < packages[i].second - currLoc.second; j++) {
                path += 'U';
            }
            currLoc = packages[i];
        }

        if (valid) {
            cout << "YES" << '\n';
            cout << path << '\n';
        } else {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
