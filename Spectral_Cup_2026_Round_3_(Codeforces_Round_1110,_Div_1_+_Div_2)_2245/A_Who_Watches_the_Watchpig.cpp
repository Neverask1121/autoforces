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
      string s;
      cin >> s;
      if(n<2*k){
        cout << -1 << endl; continue;
      }
      int answer = 0;
      for(int i = 0 ; i < k ; i++){
        if(s[i]=='L'){
          answer++;
        }
      }
      for(int i = n-k ; i < n ; i++){
        if(s[i]=='R'){
          answer++;
        }
      }
      cout << answer << endl;
    }
    return 0;
}