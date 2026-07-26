//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    //my code goes here
    int N;
    cin >> N;
    vector<char> S(N);
    for(int i = 0 ; i < N ; i++) cin >> S[i];
    int c1 = 0, c2 = 0;
    for(int i = 0 ; i < N ; i++){
        if(S[i] == 'A') c1++;
        if(S[i] == 'D') c2++;
    }
    if(c1 > c2) cout << "Anton";
    if(c1 < c2) cout << "Danik";
    else if(c1 == c2) cout << "Friendship";
    return 0;
}