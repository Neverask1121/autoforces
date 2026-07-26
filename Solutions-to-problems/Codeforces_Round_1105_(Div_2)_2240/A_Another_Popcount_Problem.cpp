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
      if(k >= n){
        cout << n << endl;
        continue;
      }
      long long one = 0;
      long long two = n;
      long long cost = 1;
      for(int i = 0 ; i <= 60 ; i++){
        if(cost > two) break;
        long long count = min((ll)k, two/cost); 
        one += count;
        two -= cost * count;
        cost *= 2;
      }
      cout << one << endl;
    }
    return 0;
}