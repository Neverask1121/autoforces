// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while(t--){
//       int n,m;
//       cin >> n >> m;
//       string x, s;
//       cin >> x >> s;
//       int count = false;
//         if (x.find(s) != std::string::npos) {
//             cout << 0 << endl;
//             continue;
//           }
//       for(int i = 1 ; i <= 25 ; i++){
//         x += x;
//         if (x.find(s) != std::string::npos) {
//             cout << i << endl;
//             count = true;
//             break;
//           }
//           if(i == 25){
//             cout << -1 << endl;
//           }
//       }
//     }
//     return 0;
// }
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
      int n,m;
      cin >> n >> m;
      string x, s;
      cin >> x >> s;
      int count = false;
      if (x.find(s) != std::string::npos) {
          cout << 0 << endl;
          continue;
      }
      int i = 0;
      while(x.size() < s.size()){
        x += x;
        i++;
        if (x.find(s) != std::string::npos) {
            cout << i << endl;
            count = true;
            break;
        }
      }
      if(count) continue;
      x += x;
      i++;
      if (x.find(s) != std::string::npos) {
          cout << i << endl;
      }
      else{
          cout << -1 << endl;
      }
    }
    return 0;
}