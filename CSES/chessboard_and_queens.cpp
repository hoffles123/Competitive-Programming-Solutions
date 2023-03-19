// classic n-queens

#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int counter = 0;
const int n = 8;
array<array<char, n>, n> board;

bool canPlace(int row, int col) {
    // N-W diagonal
    for (int r = row, c = col; r >= 0 && c >= 0; r--, c--) {
        if (board[r][c] == 'q')
            return false;
    }

    // left
    for (int c = col; c >= 0; c--) {
        if (board[row][c] == 'q')
            return false;
    }

    // S-W diagonal
    for (int r = row, c = col; r < n && c >= 0; r++, c--) {
        if (board[r][c] == 'q')
            return false;
    }

    return true;
}

void search(int col) {
    if (col >= n) {
        counter++;
        return;
    }

    for (int row = 0; row < n; row++) {
        if (board[row][col] == '*')
            continue;
        if (canPlace(row, col)) {
            board[row][col] = 'q';
            search(col + 1);
            board[row][col] = '.';
        }
    }
}

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }

    search(0);

    cout << counter << '\n';

    return 0;
}
