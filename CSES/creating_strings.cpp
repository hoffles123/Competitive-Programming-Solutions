/*
 * Generate permutations with duplicates
 * sort string first to get alphabetical order
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

void search(vector<bool>& used, const string& s, string temp, vector<string>& perm) {
    if (temp.size() == used.size()) {
        perm.push_back(temp);
        return;
    }

    for (int x = 0; x < used.size(); x++) {
        if (x > 0 && s[x] == s[x - 1] && !used[x - 1]) continue;
        if (!used[x]) {
            used[x] = true;
            search(used, s, temp + s[x], perm);
            used[x] = false;
        }
    }
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    sort(s.begin(), s.end());
    vector<bool> used(s.size());

    vector<string> perm;
    search(used, s,  "", perm);

    cout << perm.size() << "\n";
    for (auto& p : perm) {
        cout << p << "\n";
    }

    return 0;
}