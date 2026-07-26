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
      int count = 0;
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(i > 0 && a[i-1] > a[i]){
          b.push_back(1);
          count++;
        }
        b.push_back(a[i]);
      }
      int m = count + n;
      cout << m << endl;
      for(int i = 0 ; i < m ; i++){
        cout << b[i] << " ";
      }
      cout << endl;
    }
    return 0;
}