#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        bool possible = true;
        
        // Check if any two adjacent positions have same parity values
        for(int i = 0; i < n - 1; i++) {
            if(a[i] % 2 == a[i+1] % 2) {
                possible = false;
                break;
            }
        }
        
        if(possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
    
    return 0;
}