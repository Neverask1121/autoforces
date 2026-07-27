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
      int x, k;
      cin >> x >> k;
      if(x%k == 0){
        cout << 2 << endl;
        cout << -1 << " " << x+1 << endl;
        continue;
      }
      else{
        cout << 1 << endl;
        cout << x << endl;
      }
    }
    return 0;
}