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
      vector<int>array(n);
      int count =0 ;
      for(int i = 0 ; i < n ; i++){
        cin >> array[i];
        if(array[i]%2!=0){
          count++;
        }
      }
      if(count%2==0){
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
    return 0;
}