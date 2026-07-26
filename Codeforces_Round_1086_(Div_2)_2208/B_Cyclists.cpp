#include <bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--){
        int n, k, p, m;
        cin >> n >> k >> p >> m;
        vector<int> arr(n);
        for(int i = 0; i < n; i++) cin >> arr[i];
        int target = arr[p-1];
        vector<int> left;
        for(int i = 0; i < p-1; i++) left.push_back(arr[i]);
        sort(left.begin(), left.end());
        vector<int> rest;
        for(int i = 0; i < n; i++)
            if(i != p-1) rest.push_back(arr[i]);
        sort(rest.begin(), rest.end());
        int setup = max(0, p - k);
        int refill = max(0, n - k);
        long long init = target;
        for(int i = 0; i < setup; i++) init += left[i];
        if(init > m){
            cout << 0 << "\n";
            continue;
        }
        long long cycle = target;
        for(int i = 0; i < refill; i++) cycle += rest[i];
        long long budget = m - init;
        long long ans = 1 + budget / cycle;
        cout << ans << "\n";
    }
    return 0;
}