//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    //my code goes here
    int a, b;
    cin >> a >> b;
    for(int i = 0 ; i < b ; i++){
        if(a%10 == 0){
            a /= 10;
        }
        else{
            a -= 1;
        }
    }
    cout << a;
    return 0;
}