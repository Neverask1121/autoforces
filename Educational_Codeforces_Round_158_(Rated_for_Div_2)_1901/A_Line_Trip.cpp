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
    while(t--){
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }
        int ans = a[0]; // gap from 0 to a[0], adjust based on actual problem statement
        for(int i = 1; i < n; i++){
            ans = max(ans, a[i] - a[i-1]);
        }
        ans = max(ans, 2*(x - a[n-1]));
        cout << ans << endl;
    }
    return 0;
}