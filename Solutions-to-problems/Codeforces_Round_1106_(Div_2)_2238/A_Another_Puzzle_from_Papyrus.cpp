#include<bits/stdc++.h>
using namespace std;

int main(){
ios::sync_with_stdio(false);
cin.tie(nullptr);

int t;
cin>>t;
while(t--){
int n,c;
cin>>n>>c;
vector<int>a(n),b(n);
long long one=0,two=0;
for(int i=0;i<n;i++){
cin>>a[i];
one+=a[i];
}
for(int i=0;i<n;i++){
cin>>b[i];
two+=b[i];
}
long long sub=one-two;
if(sub<0){
cout<<-1<<"\n";
continue;
}
long long mini=LLONG_MAX;
bool ok=true;
for(int i=0;i<n&&ok;i++){
if(a[i]<b[i])ok=false;
}
if(ok)mini=sub;
vector<pair<int,int>>v;
for(int i=0;i<n;i++)v.push_back({a[i],b[i]});
sort(v.begin(),v.end(),[](auto &x,auto &y){
return x.first<y.first;
});
vector<int>sortedb;
for(auto &x:v)sortedb.push_back(x.second);
sort(sortedb.begin(),sortedb.end());
ok=true;
for(int i=0;i<n;i++){
if(v[i].first<sortedb[i]){
ok=false;
break;
}
}
if(ok)mini=min(mini,sub+c);
if(mini==LLONG_MAX)cout<<-1<<"\n";
else cout<<mini<<"\n";
}
return 0;
}