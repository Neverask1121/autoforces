#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define all(x) (x).begin(),(x).end()
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>A(n);
        for(int i=0;i<n;i++)cin>>A[i];
        bool ok=false;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(gcd(A[i],A[j])<=2){
                    ok=true;
                    break;
                }
            }
            if(ok)break;
        }
        cout<<(ok?"YES":"NO")<<endl;
    }
    return 0;
}