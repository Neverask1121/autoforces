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
        int n;
        cin >> n;
        vector<int>a(n);
        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }
        //inputig strings completed
        long long total_sum = 0;
        long long min_height = LLONG_MAX;
        
        for (int i = 0; i < n; i++) {
            total_sum += a[i];
            
            // Calculate maximum possible height for leveling first i+1 positions
            // This is constrained by the minimum ratio at any intermediate position
            long long max_height = total_sum / (i + 1);
            min_height = min(min_height, max_height);
            
            // Output with proper spacing
            if (i > 0) cout << " ";
            cout << min_height;
        }
        cout << "\n";
    }
    return 0;
}