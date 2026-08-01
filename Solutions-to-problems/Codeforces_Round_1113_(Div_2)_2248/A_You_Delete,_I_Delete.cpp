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
      string str;
      cin >> str;
      int n = str.length();
      string nigga;
      for(int i = 0 ; i < n ; i++){
        if(str[i] == '1'){
          continue;
        }
        string temp = str;
        temp.erase(i, 1);
        size_t pos = temp.find('1');
        if(pos == string :: npos){
          continue;
        }
        temp.erase(pos, 1);
        if(nigga.empty() || temp > nigga){
          nigga = temp;
        }
      }
      cout << nigga << endl;
    }
    return 0;
}