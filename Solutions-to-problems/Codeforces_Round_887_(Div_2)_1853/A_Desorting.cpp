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
      vector<int>a(n);
      int count = INT_MAX;
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(i > 0){
          count = min(count, a[i] - a[i-1]);
        }
      }
      if(!is_sorted(a.begin(), a.end())){
        cout << 0 << endl;
        continue;
      }
      else{
        cout << count / 2 + 1 << endl;
      }
    }
    return 0;
}