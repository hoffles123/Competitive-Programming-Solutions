// prime factorisation
#include <bits/stdc++.h>

using namespace std;

#define IO \
    freopen("../input.txt", "r", stdin); \
    freopen("../output.txt", "w", stdout);

int main() {
//    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int num = n;
        vector<int> primes;
        for (int i = 2; i*i <= n; i++) {
            while(n % i == 0) {
                n /= i;
                primes.push_back(i);
            }
        }
        if (n > 1) primes.push_back(n);

        if (primes.size() < 3) {
            cout << "NO" << '\n';
        } else if (primes.size() == 3) {
            if (primes[0] == primes[1] || primes[1] == primes[2]) {
                cout << "NO" << '\n';
            } else {
                cout << "YES" << '\n';
                cout << primes[0] << " " << primes[1] << " " << primes[2] << '\n';
            }
        } else {
            int first, second, third;
            first = primes[0];
            if (primes[1] != primes[0]) {
                second = primes[1];
            } else {
                second = primes[1] * primes[2];
            }
            third = (num / first) / (second);
            if (first == second || second == third || first == third) {
                cout << "NO" << '\n';
            } else {
                cout << "YES" << '\n';
                cout << first << " " << second << " " << third << '\n';
            }
        }
    }

    return 0;
}
