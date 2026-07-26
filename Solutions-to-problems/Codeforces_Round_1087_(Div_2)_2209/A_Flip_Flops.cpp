#include<bits/stdc++.h>
using namespace std;
int main(){
ios::sync_with_stdio(0);cin.tie(0);
int t;cin>>t;
while(t--){
long long n,c,k;cin>>n>>c>>k;
vector<long long>a(n);for(auto&x:a)cin>>x;
sort(a.begin(),a.end());
long long b=c;
for(int m=0;m<=n;m++){long long cc=c,r=k;bool ok=1;
for(int i=0;i<m;i++){if(a[i]>cc){ok=0;break;}long long f=min(r,cc-a[i]);cc+=a[i]+f;r-=f;}
if(ok)b=max(b,cc);}
cout<<b<<"\n";}
}