//By Aditya Bhandari, IIIT Vadodara, CSE
//Nearly Lucky Number in cpp

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num;
    cin >> num;

    int countLucky = 0;

    // Step 1: count lucky digits
    for(char c : num) {
        if(c == '4' || c == '7') {
            countLucky++;
        }
    }

    // Step 2: check if countLucky itself is lucky
    if(countLucky == 0) {
        cout << "NO";
        return 0;
    }

    while(countLucky > 0) {
        int digit = countLucky % 10;
        if(digit != 4 && digit != 7) {
            cout << "NO";
            return 0;
        }
        countLucky /= 10;
    }

    cout << "YES";

    return 0;
}
