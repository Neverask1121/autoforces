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

        vector<int> a(n);

        for(int i = 0 ; i < n ; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end());

        vector<int> ans(n);

        int k = 0;

        if(n % 2 == 0){
            for(int i = 0 ; i < n/2 ; i++){
                ans[k++] = a[i];
                ans[k++] = a[n-1-i];
            }
        }
        else{
            for(int i = 0 ; i < n/2 ; i++){
                ans[k++] = a[i];
                ans[k++] = a[n-1-i];
            }
            ans[k++] = a[n/2];
        }

        a = ans;

        int sum = 0;
        bool answer = true;

        for(int i = 0 ; i < n ; i++){
            if(sum == a[i]){
                answer = false;
                break;
            }
            sum += a[i];
        }

        if(answer){
            cout << "YES" << endl;
            for(int i = 0 ; i < n ; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }

    return 0;
}