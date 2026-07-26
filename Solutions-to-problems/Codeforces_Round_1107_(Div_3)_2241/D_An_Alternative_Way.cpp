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
        vector<int> b(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        ll count = 0; 
        bool check = true;
        for (int i = 0; i < n; i++) {
            count += (ll)b[i] - a[i];
            if (count < 0) {
                check = false;
                break;
            }
        }

        if (!check) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
    return 0;
}