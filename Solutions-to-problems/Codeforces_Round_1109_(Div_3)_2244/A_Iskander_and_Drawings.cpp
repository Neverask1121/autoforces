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
      string s;
      cin >> s;
      int count = 0;
      int answer = INT_MIN;
      for(int i = 0 ; i < s.length() ; i++){
        if(s[i] == '*'){
          count = 0;
        }
        else if(s[i] == '#'){
          count++;
        }
        answer = max(answer, count);
      }
      int result = std::ceil(static_cast<double>(answer) / 2);
      cout << result << endl;
    }
    return 0;
}