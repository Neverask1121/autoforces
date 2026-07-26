#include<bits/stdc++.h>
using namespace std;

vector<int> getPos(long long x,vector<long long>&v){
    vector<int> res;
    for(int i=0;i<v.size();i++)
        if(v[i]>=x) res.push_back(i);
    return res;
}

bool ok(vector<vector<int>>&p){
    for(auto &x:p)
        if(x.empty()) return false;
    return true;
}

bool assignPos(vector<vector<int>>&p,vector<int>&ans){
    int n=p.size();
    vector<int> vis(n,0);

    for(int i=0;i<n;i++){
        int pick=-1;

        for(int x:p[i]){
            if(!vis[x]){
                pick=x;
                break;
            }
        }

        if(pick==-1) return false;

        ans[i]=pick;
        vis[pick]=1;
    }

    return true;
}

long long invCount(vector<int>&v){
    long long cnt=0;
    int n=v.size();

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(v[i]>v[j]) cnt++;

    return cnt;
}

void solve(){
    int n;
    cin>>n;

    vector<long long> x(n),y(n);

    for(auto &i:x) cin>>i;
    for(auto &i:y) cin>>i;

    vector<vector<int>> pos(n);

    for(int i=0;i<n;i++)
        pos[i]=getPos(x[i],y);

    if(!ok(pos)){
        cout<<-1<<"\n";
        return;
    }

    vector<int> match(n);

    if(!assignPos(pos,match)){
        cout<<-1<<"\n";
        return;
    }

    cout<<invCount(match)<<"\n";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tc;
    cin>>tc;

    while(tc--)
        solve();

    return 0;
}
