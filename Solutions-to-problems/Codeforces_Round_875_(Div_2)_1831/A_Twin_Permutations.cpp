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
      vector<int>b;
      int look_up;
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        b.push_back(n+1-a[i]);
      }
      for(int i = 0 ; i < n ; i++){
        cout << b[i] << " ";
      }
      cout << endl;
    }
    return 0;
}