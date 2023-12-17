// disjoint set union (DSU)
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

class DSU {
    vector<int> parent, sizes;
    int numSets, largest;
public:
    explicit DSU(int n) {
        parent.resize(n);
        sizes.resize(n);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            sizes[i] = 1;
        }
        numSets = n;
        largest = 1;
    }

    int findSet(int i) {
        if (parent[i] == i)
            return i;
        parent[i] = findSet(parent[i]);
        return parent[i];
    }

    void unionSets(int i, int j) {
        i = findSet(i);
        j = findSet(j);
        if (i != j) {
            if (sizes[i] < sizes[j])
                swap(i, j);
            parent[j] = i;
            sizes[i] += sizes[j];
            numSets--;
            largest = max(largest, sizes[i]);
        }
    }

    int getNumSets() const { return numSets; }
    int getLargest() const { return largest; }
};

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    auto dsu = DSU(n);
    while(m--) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        dsu.unionSets(a, b);
        cout << dsu.getNumSets() << " " << dsu.getLargest() << '\n';
    }

    return 0;
}
