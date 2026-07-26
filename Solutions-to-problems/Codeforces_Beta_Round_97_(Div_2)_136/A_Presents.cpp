//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
 
#define ll long long
#define rep(a) rep1(i,a)
#define rep1(i,a) rep2(i,0,a)
#define rep2(i,b,a) for(int i=(b); i<(int(a)); i++)
#define all(a) a.begin(),a.end()
#define forall(a,type) for(type::iterator it=a.begin(); it!=a.end(); it++)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define mp make_pair
#define pow2(x) (1ll<<(x))
 
using namespace std;
int main() {
    int n;
    cin >> n;

    vector<int> p(n + 1);
    vector<int> ans(n + 1);

    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        ans[p[i]] = i;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}