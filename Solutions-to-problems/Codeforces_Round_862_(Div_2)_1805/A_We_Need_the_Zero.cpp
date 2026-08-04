#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        int xo = 0;                 // stores XOR of all elements
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            xo ^= x;
        }

        if (xo == 0)
            cout << 0 << '\n';
        else if (n % 2 == 1)
            cout << xo << '\n';
        else
            cout << -1 << '\n';
    }
    return 0;
}