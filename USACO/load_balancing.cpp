#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("balancing.in", "r", stdin); \
    freopen("balancing.out", "w", stdout);

int N, B;
bool outOfBounds(int i, int j) {
    if (i < 0 || j < 0 || i > B || j > B) {
        return true;
    }
    return false;
}

int dir[4][2] = {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> B;
    vector<pair<int, int>> pos(N);
    for (int x = 0; x < N; x++) {
        int i, j;
        cin >> i >> j;
        pos[x] = {i, j};
    }

    int M = 101;
    for (auto p : pos) {
        for (auto d : dir) {
            int i = p.first + d[0];
            int j = p.second + d[1];
            if (!outOfBounds(i, j)) {
                int quadrant[4] = {0};
                for (auto p2 : pos) {
                    if (p2.first < i && p2.second < j) {
                        quadrant[0]++;
                    } else if (p2.first < i && p2.second > j) {
                        quadrant[1]++;
                    } else if (p2.first > i && p2.second < j) {
                        quadrant[2]++;
                    } else {
                        quadrant[3]++;
                    }
                }
                M = min(M, *max_element(quadrant, quadrant + 4));
            }
        }
    }
    cout << M << endl;

    return 0;
}