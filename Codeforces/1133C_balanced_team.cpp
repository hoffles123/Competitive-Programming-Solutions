// sliding window
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

class Allocator {
    unordered_map<int, vector<pair<int, int>>> allocatedIdx;
    map<int, int> emptySpace;
public:
    Allocator(int n) {
        emptySpace[0] = n;
    }

    int allocate(int size, int mID) {
        int idxAllocated = -1;
        for (auto& [idx, emptySize] : emptySpace) {
            if (size <= emptySize) {
                idxAllocated = idx;
                allocatedIdx[idx].emplace_back(idx, size);
                emptySize -= size;
                if (emptySize != 0) {
                    emptySpace[idx + size] = emptySize;
                }
                emptySpace.erase(idx);
            }
            if (idxAllocated != -1)
                break;
        }
        return idxAllocated;
    }

    int free(int mID) {
        int count = 0;
        for (auto& [idx, size] : allocatedIdx[mID]) {
            count += size;
            // combine surrounding empty space
            emptySpace[idx] = size;
            if (emptySpace.count(idx + size)) {
                emptySpace[idx] += emptySpace[idx + size];
                emptySpace.erase(idx + size);
            }
            auto it = emptySpace.lower_bound(idx);
            if (it != emptySpace.begin()) {
                it--;
                if (it->first + it->second == idx) {
                    it->second += emptySpace[idx];
                    emptySpace.erase(idx);
                }
            }
        }
        allocatedIdx.erase(mID);
        return count;
    }
};

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    auto* obj = new Allocator(10);
    cout << obj->allocate(1, 1);
    cout << obj->allocate(1, 2);
    cout << obj->allocate(1, 3);
    cout << obj->free(2);

    return 0;
}
