// #include <bits/stdc++.h>
// using namespace std;

// #define ll long long
// #define endl '\n'
// #define all(x) (x).begin(), (x).end()

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t;
//     cin >>t;
//     while(t--){
//       int a,b,c,d;
//       cin >> a >> b >> c >> d;
//       //first calculate the difference;
//       int number_of_moves = 0;
//       int diff1 = c-a;
//       int diff2 = d-b;
//       if(diff2 == 0){
//         number_of_moves += abs(diff1);
//       }
//       else if(diff1>diff2 && diff1 > 0){
//         number_of_moves += diff1;
//         b += diff1;
//         number_of_moves += abs(b-d);
//       }
//       else if(diff1<diff2 && diff2 > 0){
//         number_of_moves = diff2;
//         a += diff2;
//         number_of_moves += abs(a-c);
//       }
//       if(diff1 == 0 && diff2 == 0){
//         cout << -1 << endl;
//         continue;
//       }
//       cout << number_of_moves << endl;
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
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int diff1 = c - a;
        int diff2 = d - b;
        if (diff2 < 0 || diff1 > diff2) {
            cout << -1 << endl;
            continue;
        }
        ll number_of_moves = 2LL * diff2 - diff1;
        cout << number_of_moves << endl;
    }
    return 0;
}