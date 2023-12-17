// incomplete
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("closing.in", "r", stdin); \
    freopen("closing.out", "w", stdout);

class DSU {
    vector<int> parent, sizes;
    vector<bool> isOpen;
    int numSets;
public:
    explicit DSU(int n) {
        parent.resize(n);
        sizes.resize(n);
        isOpen.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
        numSets = 0;
    }

    int findSet(int i) {
        if (parent[i] == i)
            return i;
        return parent[i] = findSet(parent[i]);
    }

    void unionSets(int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if (i != j) {
            if (sizes[i] < sizes[j])
                swap(i, j);
            parent[j] = i;
            sizes[i] += parent[j];
            numSets--;
        }
    }

    void setOpen(int i) {
        isOpen[i] = true;
        numSets++;
    }

    bool isBarnOpen(int i) { return isOpen[i]; }
    int getNumSets() const { return numSets; }
};

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    unordered_map<int, unordered_set<int>> edges;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        // bidirectional
        edges[a].insert(b);
        edges[b].insert(a);
    }

    vector<int> open(N);
    for (int i = N - 1; i >= 0; i--) {
        cin >> open[i];
        open[i]--;
    }

    auto dsu = DSU(N);
    vector<string> result;
    for (int i = 0; i < N; i++) {
        int barn = open[i];
        dsu.setOpen(barn);
        if (i == 0) {
            continue;
        }

        for (const int& neighbour : edges[barn]) {
            // if any neighbour is alrdy open, connect them
            if (dsu.isBarnOpen(neighbour)) {
                dsu.unionSets(barn, neighbour);
            }
        }

        if (dsu.getNumSets() == 1) {
            result.emplace_back("YES");
        } else {
            result.emplace_back("NO");
        }
    }

    if (dsu.getNumSets() == 1) {
        result.emplace_back("YES");
    } else {
        result.emplace_back("NO");
    }

    for (const string& s : result) {
        cout << s << '\n';
    }

    return 0;
}
