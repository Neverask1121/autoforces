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
//         int n;
//         cin >> n;

//         vector<int> a(n);

//         for(int i = 0 ; i < n ; i++){
//             cin >> a[i];
//         }

//         sort(a.begin(), a.end());

//         vector<int> ans(n);

//         int k = 0;

//         if(n % 2 == 0){
//             for(int i = 0 ; i < n/2 ; i++){
//                 ans[k++] = a[i];
//                 ans[k++] = a[n-1-i];
//             }
//         }
//         else{
//             for(int i = 0 ; i < n/2 ; i++){
//                 ans[k++] = a[i];
//                 ans[k++] = a[n-1-i];
//             }
//             ans[k++] = a[n/2];
//         }

//         a = ans;

//         int sum = 0;
//         bool answer = true;

//         for(int i = 0 ; i < n ; i++){
//             if(sum == a[i]){
//                 answer = false;
//                 break;
//             }
//             sum += a[i];
//         }

//         if(answer){
//             cout << "YES" << endl;
//             for(int i = 0 ; i < n ; i++){
//                 cout << a[i] << " ";
//             }
//             cout << endl;
//         }
//         else{
//             cout << "NO" << endl;
//         }
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
    //so if there are two strings how to find the largest suubstring that are there in the the both that are the same
    int t;
    cin >>t;
    while(t--){
        string a, b;
        cin >> a >> b;
        // so this is the next shit that is if I am doing is removing from end and from the beginnning one by one then the thing is that we need to
        // we need to do is find a optimal solution for this
        // the first test case;
        if(a == b){
            cout << 0 << endl;
            continue;
        }
        int len = 0;
        // next test case
            int n = a.size(), m = b.size();
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < m ; j++){
                    int count = 0;
                    while(i+count<n&&j+count<m&&a[i+count]==b[j+count]){
                        count++;
                    }
                    len =  max(len, count);            
                }
            }
        cout << n+m-2*len << endl;
    }
    return 0;
}

