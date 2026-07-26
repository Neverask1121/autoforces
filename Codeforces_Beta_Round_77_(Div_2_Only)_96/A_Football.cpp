//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string S;
    cin >> S;
    int count = 0;
    for(int i = 0 ; i < S.size() ; i++){
        if(S[i] == S[i-1]){
            count++;
            if(count >= 7){
                cout << "YES";
                return 0;
            }
        }
        else{
            count = 1;
        }
    }
    cout << "NO";
    return 0;
}