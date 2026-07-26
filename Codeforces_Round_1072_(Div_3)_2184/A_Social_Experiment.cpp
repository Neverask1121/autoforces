#include <bits/stdc++.h> // Includes most standard libraries
using namespace std;
int main() {
    // Fast I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    while (N--){
        int X;
        cin >> X;
        int sum = 0 ;
        if (X == 3) cout << 3 << endl;
        else if (X == 2) cout << 2 << endl;
        else if (X%2 == 0) cout << 0 << endl;
        else cout << 1 << endl;
    }
    return 0;
}