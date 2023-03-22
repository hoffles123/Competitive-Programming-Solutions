#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("notlast.in", "r", stdin); \
    freopen("notlast.out", "w", stdout);

#define ll long long

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, int> milkProduced;
    milkProduced["Bessie"] = 0;
    milkProduced["Elsie"] = 0;
    milkProduced["Daisy"] = 0;
    milkProduced["Gertie"] = 0;
    milkProduced["Annabelle"] = 0;
    milkProduced["Maggie"] = 0;
    milkProduced["Henrietta"] = 0;

    int N;
    cin >> N;
    while(N--) {
        string name;
        int milk;
        cin >> name >> milk;
        milkProduced[name] += milk;
    }

    map<int, string> orderedMilk;
    for (auto const &[cow, milk] : milkProduced) {
        orderedMilk[milk] = cow;
    }

    int minProduced = orderedMilk.begin()->first;

    auto it = orderedMilk.upper_bound(minProduced);
    if (it == orderedMilk.end()) {
        cout << "Tie" << '\n';
        return 0;
    }

    cout << it->second << '\n';

    return 0;
}
