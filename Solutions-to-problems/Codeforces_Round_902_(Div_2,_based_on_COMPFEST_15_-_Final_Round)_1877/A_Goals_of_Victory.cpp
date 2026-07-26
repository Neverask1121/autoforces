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
      int sum = 0;
      for(int i = 0 ; i < n-1 ; i++){
        cin >> a[i];
        sum += a[i];
      }
      cout << -sum << endl;
    }
    return 0;
}