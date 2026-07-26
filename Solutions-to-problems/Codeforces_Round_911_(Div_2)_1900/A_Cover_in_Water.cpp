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
      int count = 0;
      for(int i = 0 ; i < n ; i++){
        if(count >= 3){
          break;
        }
        else if(s[i] == '#'){
          count = 0;
        }
        else{
          count++;
        }
      }
      if(count == 3){
        cout << 2 << endl;
        continue;
      }
      else{
        int counta = 0;
        for(int i = 0 ; i < n ; i++){
          if(s[i] == '.'){
            counta++;
          }
        }
        if(count != 3){
          cout << counta << endl;
          continue;
        }
      }
    }
    return 0;
}