// backtrack all possible bucket transfer simulations
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

unordered_set<int> milkLvl;

void search(unordered_map<int, int>& firstBuckets,unordered_map<int, int>& secondBuckets, bool isFirst,
            int iterations, int milk) {
   if (iterations == 5) {
       milkLvl.insert(milk);
       return;
   }

   if (isFirst) {
       for (auto i : firstBuckets) {
           int k = i.first;
           int v = i.second;
            if (v > 0) {
                milk -= k;
                firstBuckets[k]--;
                secondBuckets[k]++;
                search(firstBuckets, secondBuckets, false, iterations + 1, milk);
                milk += k;
                firstBuckets[k]++;
                secondBuckets[k]--;
            }
       }
   } else {
        for (auto i : secondBuckets) {
                int k = i.first;
                int v = i.second;
            if (v > 0) {
                milk += k;
                secondBuckets[k]--;
                firstBuckets[k]++;
                search(firstBuckets, secondBuckets, true, iterations + 1, milk);
                milk -= k;
                secondBuckets[k]++;
                firstBuckets[k]--;
            }
        }
   }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<int, int> firstBuckets;
    unordered_map<int, int> secondBuckets;

    int b;
    for (int i = 0; i < 10; i++) {
        cin >> b;
        firstBuckets[b]++;
    }
    for (int i = 0; i < 10; i++) {
        cin >> b;
        secondBuckets[b]++;
    }

    search(firstBuckets, secondBuckets, true, 1, 1000);

    cout << milkLvl.size() << endl;

    return 0;
}
