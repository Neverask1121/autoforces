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
      int n,m;
      cin >> n >> m;
      vector<int>a(n);
      vector<int>b(m);
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
      }
      for(int i = 0 ; i < m ; i++){
        cin >> b[i];
      }
      sort(a.begin(), a.end());
      sort(b.begin(), b.end());
      bool nigga = true;
      if(n < 2LL * m){
        nigga = false;
      }
      else{
        for(int i = 0 ; i < m ; i++){
          if(a[i]>=b[i] || a[n-m+i] <= b[i]){
            nigga = false;
            break;
          }
        }
      } 
      if(nigga){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
      
    }
    return 0;
}