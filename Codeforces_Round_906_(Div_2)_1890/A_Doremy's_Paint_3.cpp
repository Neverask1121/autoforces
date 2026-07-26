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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        unordered_set<int> unique_elements(a.begin(), a.end());
        int l = unique_elements.size();

        if (n <= 2) {
            cout << "YES" << endl;
            continue;
        }
        else if (l >= 3) {
            cout << "NO" << endl;
            continue;
        }
        else if (l == 1) {
            cout << "YES" << endl;
            continue;
        }
        else if (l == 2) {
            vector<int> v(unique_elements.begin(), unique_elements.end());

            int count_0 = count(a.begin(), a.end(), v[0]);
            int count_1 = count(a.begin(), a.end(), v[1]);

            if (abs(count_0 - count_1) <= 1) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}