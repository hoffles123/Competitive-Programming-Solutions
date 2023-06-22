#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("lifeguards.in", "r", stdin); \
    freopen("lifeguards.out", "w", stdout);

struct StartEndTime {
    int idx;
    int time;
};

bool cmp(const StartEndTime& i, const StartEndTime& j) {
    return i.time < j.time;
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<StartEndTime> timings(2*n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        timings[2*i] = StartEndTime{i, a};
        timings[2*i+1] = StartEndTime{i, b};
    }

    sort(timings.begin(), timings.end(), cmp);

    unordered_set<int> seen;
    vector<int> alone(n);
    int prev = 0;
    int count = 0;
    for (const auto& timing: timings) {
        if (seen.size() == 1) {
            alone[*seen.begin()] += timing.time - prev;
        }
        if (!seen.empty()) {
            count += timing.time - prev;
        }
        if (seen.count(timing.idx)) {
            seen.erase(timing.idx);
        } else {
            seen.insert(timing.idx);
        }
        prev = timing.time;
    }

    int result = 0;
    for (const auto& a : alone) {
        result = max(result, count - a);
    }

    cout << result << '\n';

    return 0;
}
