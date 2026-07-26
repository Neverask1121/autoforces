//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    if(cin >> t){
        while(t--){
            long long n, w;
            cin >> n >> w;
            cout << n-(n/w) << "\n";
        }
    }
    //my code goes here
    return 0;
}