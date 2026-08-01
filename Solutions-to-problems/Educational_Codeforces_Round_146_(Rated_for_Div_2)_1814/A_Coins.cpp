#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while(t--){
      ll n, k;
      cin >> n >> k;
      if(n%(k+2) == 0 || n%k == 0 || n%2 == 0 || (n-k+2)%2==0 || (n-k+2)%k==0){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    return 0;
}