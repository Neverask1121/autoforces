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
      int n, k;
      cin >> n >> k;
      vector<int>a(n);
      bool check = false;
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(a[i] == k){
          check = true;
        }
      }
      if(check){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    return 0;
}
