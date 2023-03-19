/*
 * Some combination of air-cons will satisfy all cows and have the min cost.
 * Complete search on all combinations/subsets of air-cons
 * time complexity = 2^N * M
 */
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

struct Cow {
    int startStall;
    int endStall;
    int cool;
};

struct AC {
    int startStall;
    int endStall;
    int temp;
    int cost;
};

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Cow> cows;
    vector<AC> acs;

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        int s, t, c;
        cin >> s >> t >> c;
        Cow cow{s, t, c};
        cows.push_back(cow);
    }
    for (int i = 0; i < M; i++) {
        int a, b, p, m;
        cin >> a >> b >> p >> m;
        AC ac{a, b, p, m};
        acs.push_back(ac);
    }

    int minCost{10*1000 + 1};

    for (int mask = 0; mask < (1 << M); mask++) {
        int cost{};
        unordered_map<int, int> temps;
        for (int i = 0; i < M; i++) {
            if (mask & (1 << i)) {
                cost += acs[i].cost;
                for (int stall{acs[i].startStall}; stall <= acs[i].endStall; stall++) {
                    temps[stall] += acs[i].temp;
                }
            }
        }
        bool valid{true};
        // check all cows are comfy
        for (int i = 0; i < N; i++) {
            for (int stall{cows[i].startStall}; stall <= cows[i].endStall; stall++) {
                if (temps[stall] < cows[i].cool) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (valid) minCost = min(minCost, cost);
    }

    cout << minCost << '\n';

    return 0;
}
