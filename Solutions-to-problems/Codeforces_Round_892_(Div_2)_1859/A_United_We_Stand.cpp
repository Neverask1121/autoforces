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
//       vector<int>a(n);
//       for(int i = 0 ; i < n ; i++){
//         cin >> a[i];
//       }
//       vector<int>b;
//       vector<int>c;
//       sort(a.begin(), a.end());
//       int i = 0;      
//       b.push_back(a[0]);
//       i++;
//       while(a[i-1] == a[i]){
//         b.push_back(a[i]);
//         i++;
//       }
//       for(int j = i ; j < n ; j++){
//         c.push_back(a[i]);
//       }
//       int lb = b.size();
//       int lc = c.size();
//       cout << lb << " " << lc << endl;
//       for(int i = 0 ; i < lb ; i++){
//         cout << b[i];
//       }
//       cout << endl;
//       for(int i = 0 ; i < lc ; i++){
//         cout << c[i];
//       }
//       cout << endl;
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
        int n;
        cin >> n;                           // FIX: read n first
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // Handle empty vector (optional but safe)
        if (n == 0) {
            cout << "0 0\n\n\n";
            continue;
        }

        vector<int> b, c;
        sort(a.begin(), a.end());

        // Put all occurrences of the minimum element into b
        b.push_back(a[0]);
        int i = 1;
        while (i < n && a[i - 1] == a[i]) { // FIX: bounds check
            b.push_back(a[i]);
            i++;
        }

        // Put the rest into c
        for (int j = i; j < n; j++) {
            c.push_back(a[j]);              // FIX: use j, not i
        }

        int lb = b.size();
        int lc = c.size();
        if(lb == 0 || lc == 0){
          cout << -1 << endl;
          continue;
        }

        cout << lb << " " << lc << endl;

        // Print b with spaces
        for (int i = 0; i < lb; i++) {
            cout << b[i] << (i + 1 == lb ? '\n' : ' ');
        }
        // Print c with spaces
        for (int i = 0; i < lc; i++) {
            cout << c[i] << (i + 1 == lc ? '\n' : ' ');
        }
        // cout << endl; // extra blank line between test cases (optional)
    }
    return 0;
}