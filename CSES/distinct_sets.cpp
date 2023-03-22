#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

#define ll long long

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    unordered_set<int> distinct;
    while(n--) {
        int i;
        cin >> i;
        distinct.insert(i);
    }

    cout << distinct.size() << endl;

    return 0;
}
