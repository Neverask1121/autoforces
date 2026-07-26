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
      int n, x, y;
      cin >> n >> x >> y;
      vector<int>a(n);
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
      }
      // if(abs(x-y) == 1 || abs(x-y) == 0){
      //   cout << "YES" << endl;
      // }
      // else{
      //   cout << "NO" << endl;
      // }
      bool checking = true;
      int gcd_of_x_y = gcd(x,y);
      for(int i = 0 ; i < n ; i++){
        if((a[i]-(i+1)) % gcd_of_x_y != 0){
          checking = false;
          break;
        }
      }
      if(checking){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    return 0;
}