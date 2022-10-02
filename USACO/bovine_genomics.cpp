#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("cownomics.in", "r", stdin); \
    freopen("cownomics.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    // store the genes in sets
    vector<unordered_set<char>> spottyPos(M);
    vector<unordered_set<char>> plainPos(M);
    for (int i = 0; i < N * 2; i++) {
        for (int j = 0; j < M; j++) {
            char gene;
            cin >> gene;
            if (i < N) {
                spottyPos[j].insert(gene);
            } else {
                plainPos[j].insert(gene);
            }
        }
    }

    // if all genes in spotty set not found in plain set, increment count
    int count = 0;
    for (int pos = 0; pos < M; pos++) {
        unordered_set<char>::iterator it;
        for (it = spottyPos[pos].begin(); it != spottyPos[pos].end(); it++) {
            if (plainPos[pos].count(*it))
                break;
        }
        if (it == spottyPos[pos].end())
            count++;
    }
    cout << count << endl;

    return 0;
}