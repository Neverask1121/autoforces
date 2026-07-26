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
      ll c;
      cin >> n >> c;
      vector<ll> a(n);
      ll sum = 0;
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        sum += a[i];
      }
      sort(a.begin(), a.end());
      int p = 0;
      while(p<n && a[p]<c){
        p++;
      }
      int m = min(p, n/2);
      ll nigga = 0;
      for(int i = 0 ; i< m ;i++){
        nigga += (c-a[i]);
      }
      ll answer = sum - c * n + nigga;
      cout << answer << endl;
      // for(int i = 0 ; i < n ; i++){
      //   if(c == 0){
      //     if(a[i]>0){
      //       sum += a[i];
      //     }
      //   }
      //   else{
      //     vector<int> temp = a;
      //     sort(temp.begin(), temp.end(), std::greater<int>());
      //     if(temp.size() / 2 == 0){
      //       for(int i = 0 ; i < temp.size() / 2 ; i++){
      //         sum += temp[i];
      //       }
      //     }
      //     else{
      //       for(int i = 0 ; i < temp.size() / 2 - 1 ; i++){
      //         sum += temp[i];
      //       }
      //     }
      //   }
      //   cout << sum << endl;
      }
    return 0;
}