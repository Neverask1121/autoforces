#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        int mn = *min_element(all(a));
        bool ok = (a[0] == mn);

        if (ok) {
            vector<int> suff(n + 1, INT_MAX);
            for (int i = n - 1; i >= 0; i--)
                suff[i] = min(a[i], suff[i + 1]);

            for (int i = 0; i < n - 1; i++) {
                if (a[i] == a[i + 1]) {
                    // suffix after the pair must be >= a[i]
                    if (suff[i + 2] < a[i]) {
                        ok = false;
                        break;
                    }
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
    return 0;
}