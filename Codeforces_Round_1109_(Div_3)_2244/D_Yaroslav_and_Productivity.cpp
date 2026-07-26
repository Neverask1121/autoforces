// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--){
//       int n, m;
//       cin >> n >> m;
//       vector<int>a(n);
//       vector<int>b(m);
//       for(int i = 0 ; i < n ; i++){
//         cin >> a[i];
//       }
//       for(int i = 0 ; i < m ; i++){
//         cin >> b[i];
//       }
//       vector<int> cigga(n, 0);
//       for (int i = 0; i < n; ++i) {
//           int nigga = 0;
//           for (int j = 0; j < m; ++j) {
//               if (b[j] >= i + 1) nigga |= (1 << j);
//           }
//           cigga[i] = nigga;
//       }
//       ll best = LLONG_MIN;
//       for (int nigga = 0; nigga < (1 << m); ++nigga) {
//           ll sum = 0;
//           for (int i = 0; i < n; ++i) {
//               int parity = __builtin_popcount(nigga & cigga[i]) & 1;
//               sum += (parity ? -a[i] : a[i]);
//           }
//           best = max(best, sum);
//       }
//       cout << best << endl;
//     }
//     return 0;
// }
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
        int n, m;
        cin >> n >> m;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        vector<int> b(m);
        for (int i = 0; i < m; i++) cin >> b[i];
        vector<ll> nigga(n + 1, 0);
        for (int i = 0; i < n; i++) {
            nigga[i + 1] = nigga[i] + a[i];
        }
        sort(b.begin(), b.end());
        int bio = 0;
        ll ans = 0;
        for (int j = 0; j < m; j++) {
            int cigga = b[j];
            ll seg = nigga[cigga] - nigga[bio];  
            ans += llabs(seg);                 
            bio = cigga;
        }
        ll last = nigga[n] - nigga[bio];
        ans += last;                           
        cout << ans << endl;
    }
}