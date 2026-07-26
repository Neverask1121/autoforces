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
      if(n < 3){
        cout << "First" << endl;
      }
      else if(n % 3 == 0){
        cout << "Second" << endl;
      }
      else{
        cout << "First" << endl;
      }
    }
    return 0;
}