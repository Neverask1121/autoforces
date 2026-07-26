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
      bool check = true;
      long long nigga = 0;
      for(int i = 1 ; i <= n ; i++){
        long long m;
        cin >> m;
        nigga += m;
        long long require = 1LL * i * (i+1) / 2;
        if(nigga<require){
          check = false;
        }
      }
      cout << (check ? "YES" : "NO") << endl;
    }
    return 0;
}