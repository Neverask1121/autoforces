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
//       int n;
//       cin >> n;
//       vector<int> a(n);
//       // if I have product of all elements and then iterate in the array such that I will get the product then I will get the answer here
//       int product = 1;
//       for(int i = 0 ; i < n ; i++){
//         cin >> a[i];
//         product *= a[i];

//       }
//       int pro = 1;
//       int ans;
//       // see so I have this array of elements I need to find a k position that does is divides the vector into two parts
//       for(int i = 0 ; i < n ; i++){
//         pro *= a[i];
//         if(pro == (product / 2)/2){
//           // then I will have to break from loop and store the I and output the I
//           ans = i; 
//           break;
//         }
//       }
//       cout << ans+1 << endl;
//     }
//     return 0;
// }
// //1 pass then number of integers 6 pass then input pass then calculating total product pass then input is 2 2 1 2 1 2 then
// // total product is 16 then 16 / 2 is 8 then 8 ka bhi by 2 karna hai




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
      vector<int> a(n);
      // if I have product of all elements and then iterate in the array such that I will get the product then I will get the answer here
      int product = 0;
      for(int i = 0 ; i < n ; i++){
        cin >> a[i];
        if(a[i] == 2) product++;
      }

      if(product % 2){
        cout << -1 << endl;
        continue;
      }

      int pro = 0;
      int ans = -1;
      // see so I have this array of elements I need to find a k position that does is divides the vector into two parts
      for(int i = 0 ; i < n-1 ; i++){
        if(a[i] == 2) pro++;
        if(pro == product / 2){
          // then I will have to break from loop and store the I and output the I
          ans = i;
          break;
        }
      }

      if(ans == -1) cout << -1 << endl;
      else cout << ans + 1 << endl;
    }
    return 0;
}
//1 pass then number of integers 6 pass then input pass then calculating total product pass then input is 2 2 1 2 1 2 then
// total product is 16 then 16 / 2 is 8 then 8 ka bhi by 2 karna hai