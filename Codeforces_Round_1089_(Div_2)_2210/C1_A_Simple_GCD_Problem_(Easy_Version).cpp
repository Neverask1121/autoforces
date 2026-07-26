#include<bits/stdc++.h>
using namespace std;

long long g(long long x,long long y){while(y)x%=y,swap(x,y);return x;}
long long l(long long x,long long y){return x&&y?(x/g(x,y))*y:0;}

void work(){
    int m; cin>>m;
    vector<long long> v(m), w(m);
    for(auto &i:v) cin>>i;
    for(auto &i:w) cin>>i;
    int res=0;
    for(int i=0;i<m;i++){
        long long t=(i==0?g(v[0],v[1]):(i==m-1?g(v[m-2],v[m-1]):l(g(v[i-1],v[i]),g(v[i],v[i+1]))));
        if(t<v[i]) res++;
    }
    cout<<res<<"\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin>>t; while(t--) work();
}