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
        int cnt = 0, max_cnt = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (a[i] == 0) {
                cnt++;
                max_cnt = max(max_cnt, cnt);
            } else {
                cnt = 0;
            }
        }
        cout << max_cnt << endl;
    }
    return 0;
}