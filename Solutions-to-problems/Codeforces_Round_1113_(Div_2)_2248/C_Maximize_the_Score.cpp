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
      int dam = 2 *n;
      vector<int>a(n+1, 0);
      vector<ll>b(dam+1, 0);
      for(int i = 1 ; i <= dam ; i++){
        int nigga;
        cin >> nigga;
        b[i] = b[i-1];
        if(a[nigga] != 0){
          int l = a[nigga];
          ll leh = i - l + 1LL;
          ll ggs = leh * leh - leh;
          b[i]=max(b[i], b[l - 1]+ggs);
        }
        else{
          a[nigga]=i;
        }
      }
      cout<< 2LL*n+b[dam] << endl;
    }
    return 0;
}