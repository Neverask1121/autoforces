#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    cin >> text;
    
    if (text.find('H') != string::npos || 
        text.find('Q') != string::npos || 
        text.find('9') != string::npos) {
        cout << "YES";
    } else {
        cout << "NO";
    }
    
    return 0;
}