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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> pref0(n+1,0), pref1(n+1,0);
        vector<int> pairPref0(n,0), pairPref1(n,0);
        for(int i=0;i<n;i++){
            char exp0 = (i%2==0?'0':'1'); char exp1 = (i%2==0?'1':'0');
            pref0[i+1] = pref0[i] + (s[i]!=exp0); pref1[i+1] = pref1[i] + (s[i]!=exp1);
        }
 for(int i=0;i<n-1;i++){
            char exp0_i = (i%2==0?'0':'1');
    char gf = ((i+1)%2==0?'0':'1');char exp1_i = (i%2==0?'1':'0');
            char exp1_i1 = ((i+1)%2==0?'1':'0');
            pairPref0[i+1] = pairPref0[i] + (s[i]!=exp0_i && s[i+1]!=gf);  pairPref1[i+1] = pairPref1[i] + (s[i]!=exp1_i && s[i+1]!=exp1_i1);
        }
 while(q--){
            int l, r, k;
         cin >> l >> r >> k;
            --l; --r;
         int mis0 = pref0[r+1] - pref0[l];
          int adj0 = pairPref0[r] - pairPref0[l];
         int runs0 = mis0 - adj0;
            int mis1 = pref1[r+1] - pref1[l];
         int gf1 = pairPref1[r] - pairPref1[l];
         int runs1 = mis1 - gf1;
            int need = min(runs0, runs1);
        if(need <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
        }
    }
    return 0;
}