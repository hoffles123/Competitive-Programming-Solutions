// iterate through next permutations and check all constraints
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("lineup.in", "r", stdin); \
    freopen("lineup.out", "w", stdout);

bool nextPermutation(vector<string>& cows) {
    int n = cows.size();
    int i = n - 1;
    while(--i >= 0) {
        if (cows[i] < cows[i + 1]) break;
    }

    if (i == -1) return false;

    reverse(cows.begin() + i + 1, cows.end());
    auto it = upper_bound(cows.begin() + i + 1, cows.end(), cows[i]);
    int j = it - cows.begin();
    swap(cows[i], cows[j]);
    return true;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> cows{"Bessie", "Buttercup", "Belinda", "Beatrice", "Bella", "Blue", "Betsy", "Sue"};
    sort(cows.begin(), cows.end());

    int N;
    cin >> N;
    vector<pair<string, string>> constraints;
    string s, tmp;
    char delim = ' ';
    while(getline(cin, s)) {
        vector<string> words;
        stringstream ss(s);
        while(getline(ss, tmp, delim)) {
            words.push_back(tmp);
        }
        if (words.size() != 0) {
            constraints.emplace_back(words[0], words[5]);
        }
    }

    do {
        bool valid = true;
        // check all constraints are met
        for (const auto& p : constraints) {
            string cow1 = p.first;
            string cow2 = p.second;
            for (int i = 0; i < cows.size(); i++) {
                if (cows[i] == cow1) {
                    bool left = i == 0 || (i > 0 && cows[i - 1] != cow2);
                    bool right = i == cows.size() - 1 || (i <= cows.size() - 2 && cows[i + 1] != cow2);
                    if (left && right) {
                        valid = false;
                        break;
                    }
                }
            }
            if (!valid) break;
        }
        if (!valid) continue;

        for (const auto& cow : cows) {
            cout << cow << '\n';
        }
        return 0;

    } while(nextPermutation(cows));

    return 0;
}