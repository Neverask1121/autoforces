#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        for(int i = 0 ; i<n ; i++){
            cin >> a[i];
        }
        unordered_set<int> length;
        for(int i = 0 ; i<n ; i++){
            length.insert(a[i]);
        }
        if(k >= 2 || length.size() == 1 || is_sorted(a.begin(), a.end())){
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }
}
