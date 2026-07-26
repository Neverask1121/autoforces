//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    string s;
    cin >> n >> s;
    int count = 0;
    for (int i = 0 ; i < s.size() ; i++){
        if (s[i] == s[i+1]){
            count++;
        }
    }
    cout << count << endl;
    //my code goes here
    return 0;
}