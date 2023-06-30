/*
 * for each cow
 * - dfs once first without crossing roads, to get all non-distant cows and store them
 * - dfs again and can cross roads, if meet a cow that was not visited before, they are distant
 */

#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("countcross.in", "r", stdin); \
    freopen("countcross.out", "w", stdout);

using ii = pair<int, int>;

struct hashFunc {
    size_t operator()(const ii &x) const {
        return x.first ^ x.second;
    }
};

unordered_set<ii, hashFunc> cows;
unordered_map<ii, set<ii>, hashFunc> roads;
unordered_set<ii, hashFunc> distantCows;
unordered_map<ii, int, hashFunc> cowIdx;

void dfs(vector<vector<bool>>& visited, unordered_set<ii, hashFunc>& cowsVisited, int r, int c, bool withRoads, int originCow) {
    if (r < 0 || c < 0 || r >= visited.size() || c >= visited[0].size()) return;
    if (visited[r][c]) return;
    if (cows.count({r, c})) {
        if (withRoads) {
            // if have not seen cow before with roads, they are distant
            if (!cowsVisited.count({r, c})) {
                int idx1 = originCow;
                int idx2 = cowIdx[{r, c}];
                if (idx2 < idx1) swap(idx2, idx1);
                distantCows.insert({idx1, idx2});
            }
        } else {
            cowsVisited.insert({r, c});
        }
    }

    visited[r][c] = true;

    if (withRoads) {
        dfs(visited, cowsVisited, r + 1, c, withRoads, originCow);
        dfs(visited, cowsVisited, r - 1, c, withRoads, originCow);
        dfs(visited, cowsVisited, r, c + 1, withRoads, originCow);
        dfs(visited, cowsVisited, r, c - 1, withRoads, originCow);
    } else {
        if (!roads[{r, c}].count({r + 1, c})) dfs(visited, cowsVisited, r + 1, c, withRoads, originCow);
        if (!roads[{r, c}].count({r - 1, c})) dfs(visited, cowsVisited, r - 1, c, withRoads, originCow);
        if (!roads[{r, c}].count({r, c + 1})) dfs(visited, cowsVisited, r, c + 1, withRoads, originCow);
        if (!roads[{r, c}].count({r, c - 1})) dfs(visited, cowsVisited, r, c - 1, withRoads, originCow);
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, R;
    cin >> N >> K >> R;
    while(R--) {
        int r, c, r1, c1;
        cin >> r >> c >> r1 >> c1;
        r--, c--, r1--, c1--;
        // bidirectional roads
        roads[{r, c}].insert({r1, c1});
        roads[{r1, c1}].insert({r, c});
    }
    while(K--){
        int r, c;
        cin >> r >> c;
        r--, c--;
        cows.insert({r, c});
        cowIdx[{r, c}] = K;
    }

    for (const auto& cow : cows) {
        int idx = cowIdx[{cow.first, cow.second}];
        // dfs once with no roads
        vector<vector<bool>> visited(N, vector<bool>(N));
        unordered_set<ii, hashFunc> cowsVisited;
        dfs(visited, cowsVisited, cow.first, cow.second, false, idx);

        // dfs again with roads
        vector<vector<bool>> visited1(N, vector<bool>(N));
        dfs(visited1, cowsVisited, cow.first, cow.second, true, idx);
    }

    cout << distantCows.size() << '\n';

    return 0;
}

