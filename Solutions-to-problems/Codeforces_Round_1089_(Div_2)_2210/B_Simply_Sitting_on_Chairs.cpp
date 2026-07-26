#include<bits/stdc++.h>
using namespace std;

void run(){
    int x; cin>>x;
    vector<int> v(x+1), d(x+3);
    for(int i=1;i<=x;i++) cin>>v[i];
    for(int i=1;i<=x;i++){
        int l=i+1, r=(v[i]<=i?x+1:v[i]);
        d[l]++, d[r+1]--;
    }
    int cur=0, ans=0;
    for(int i=1;i<=x+1;i++) cur+=d[i], ans=max(ans,cur);
    cout<<ans<<"\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--) run();
}