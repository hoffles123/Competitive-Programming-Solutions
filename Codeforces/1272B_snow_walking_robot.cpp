// simply check that U and D/R and L are equal and construct a rectangle path
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while(q--) {
        string s;
        cin >> s;
        array<int, 4> dir{}; // U D L R
        for (const char& c : s) {
            switch (c) {
                case 'U':
                    dir[0]++;
                    break;
                case 'D':
                    dir[1]++;
                    break;
                case 'L':
                    dir[2]++;
                    break;
                case 'R':
                    dir[3]++;
            }
        }
        int vertical = min(dir[0], dir[1]);
        int horizontal = min(dir[2], dir[3]);

        if (vertical && !horizontal) {
            cout << 2 << '\n';
            cout << "UD" << '\n';
            continue;
        }
        if (!vertical && horizontal) {
            cout << 2 << '\n';
            cout << "LR" << '\n';
            continue;
        }

        string ans = string(vertical, 'U') + string(horizontal, 'R') + string(vertical, 'D') + string(horizontal, 'L');
        cout << ans.size() << '\n';
        cout << ans << '\n';
    }

    return 0;
}
