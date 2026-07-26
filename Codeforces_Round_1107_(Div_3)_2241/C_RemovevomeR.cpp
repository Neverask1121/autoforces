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
      string s;
      cin >> s;
      bool check = true;
      for (int i = 0; i + 1 < n; i++) {
          if (s[i] != s[i + 1]) {
              check = false;
              break;
          }
      }
      if(check){
        cout << '1' << endl;
        continue;
      }
      bool char1 = false;
      bool char2 = false;
      for(int i = 0 ; i+1 < n ; i++){
        if(s[i] == '0' && s[i+1] == '1'){
          char1 = true;
        }
        if(s[i] == '1' && s[i+1] == '0'){
          char2 = true;
        }
      }
      if(!char1 || !char2 ){
        cout << 2 << endl;
      }
      else{
        cout << 1 << endl;
      }

    }
    return 0;
}