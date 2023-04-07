#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("bcount.in", "r", stdin); \
    freopen("bcount.out", "w", stdout);

void printBreed(vector<tuple<int, int, int>>& sum, int a, int b) {
    if (a == 0) {
        cout << get<0>(sum[b]) << " " << get<1>(sum[b]) << " " << get<2>(sum[b]) << '\n';
    } else {
        cout << get<0>(sum[b]) - get<0>(sum[a - 1]) << " " << get<1>(sum[b]) - get<1>(sum[a - 1]) << " " << get<2>(sum[b]) - get<2>(sum[a - 1]) << '\n';
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<tuple<int, int, int>> prefix(N);
    tuple<int, int, int> sum{0, 0, 0};
    for (int i = 0; i < N; i++) {
        int breed;
        cin >> breed;
        switch(breed) {
            case 1:
                get<0>(sum)++;
                break;
            case 2:
                get<1>(sum)++;
                break;
            case 3:
                get<2>(sum)++;
                break;
        }
        prefix[i] = sum;
    }

    while(Q--) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        printBreed(prefix, a, b);
    }

    return 0;
}
