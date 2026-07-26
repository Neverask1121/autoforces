#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, k, x;
        cin >> n >> k >> x;
        if (x != 1) {
            cout << "YES\n";
            cout << n << "\n";
            for (int i = 0; i < n; i++) cout << 1 << " \n"[i == n - 1];
        } else if (k == 1 || (k == 2 && n % 2 == 1)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            cout << n / 2 << "\n";
            long long first = (n % 2 == 1) ? 3 : 2;
            cout << first;
            for (int i = 0; i < n / 2 - 1; i++) cout << " " << 2;
            cout << "\n";
        }
    }
    return 0;
}