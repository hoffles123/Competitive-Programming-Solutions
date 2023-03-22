// sort cows by arrival time. Add time based on questioning time
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("cowqueue.in", "r", stdin); \
    freopen("cowqueue.out", "w", stdout);

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> cows(N);
    while(N--) {
        int arrival, question;
        cin >> arrival >> question;
        cows.emplace_back(arrival, question);
    }

    sort(cows.begin(), cows.end());

    int time = 0;
    for (const auto& cow : cows) {
        if (time < cow.first) {
            time = cow.first;
        }
        time += cow.second;
    }

    cout << time << '\n';


    return 0;
}
