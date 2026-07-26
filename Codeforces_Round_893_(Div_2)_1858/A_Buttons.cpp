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
      int a, b, c;
      cin >> a >> b >> c;
      if(a == b && c % 2 == 0){
        cout << "Second" << endl;
      }
      else if(a == b && c % 2 != 0){
        cout << "First" << endl;
      }
      else if(a > b){
        cout << "First" << endl;
      }
      else if(a < b){
        cout << "Second" << endl;
      }
    }
    return 0;
}