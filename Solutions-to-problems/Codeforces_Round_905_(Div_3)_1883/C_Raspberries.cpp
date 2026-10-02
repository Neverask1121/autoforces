#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int>a(n);
        int ans = INT_MAX;
        int cnt = 0;

        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(a[i]%2==0)
                cnt++;
        }

        for(int i = 0; i < n; i++){
            ans = min(ans, (k-a[i]%k)%k);
        }

        if(k == 4){
            if(cnt >= 2)
                ans = 0;
            else if(cnt == 1)
                ans = min(ans, 1);
            else
                ans = min(ans, 2);
        }

        cout << ans << endl;
    }
}