#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a,b;
    cin >> a >>b;
    string ans;
    int n = a.size();
    for(int i = 0 ; i < n ; i++){
        if(a[i]!=b[i]){
            ans+='1';
        }
        else
        {
            ans+='0';
        }
        
    }
    cout << ans<<endl;
    return 0;
}