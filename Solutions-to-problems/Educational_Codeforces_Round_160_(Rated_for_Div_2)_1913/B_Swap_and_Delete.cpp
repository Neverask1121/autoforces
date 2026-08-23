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
      string s;
      cin >> s;
      // string temp = s;
      int count = 0;
      int n = s.length();
      int count1 = 0;
      int count2 = 0;
      for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
          count1++;
        }
        else{
          count2++;
        }
      }
      // count = abs(count1 - count2);
      // int count3 = 0;
      // int count4 = 0;
      // for(int i = 0 ; i < n-count ; i++){
      //   if(s[i] == '1'){
      //     count3++;
      //   }
      //   else{
      //     count4++;
      //   }        
      // }
      // count += abs(count3 - count4) / 2;
      // cout << count << endl;
      for(int i = 0 ; i < n ; i++){
        if(s[i] == '1'){
          count2--;
        }
        else if(s[i] == '0'){
          count1--;
        }
        if(count1<0 || count2<0){
          count = n - i ;
          break;
        }
      }
      cout << count << endl;
    }
    return 0;
}