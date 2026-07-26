//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>

#define ll long long
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string y;
    cin >> y;

    int year = stoi(y);  // convert string to integer

    while(true){
        year++;                 // increment numerically
        y = to_string(year);   // convert back to string

        if(y[0]!=y[1] && y[0]!=y[2] && y[0]!=y[3] &&
           y[1]!=y[2] && y[1]!=y[3] &&
           y[2]!=y[3]){
            cout << y;
            return 0;
        }
    }
}
