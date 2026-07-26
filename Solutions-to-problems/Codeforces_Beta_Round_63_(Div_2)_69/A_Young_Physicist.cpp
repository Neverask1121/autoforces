//By Aditya Bhandari, IIIT Vadodara, CSE
//in cpp
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    int sumx = 0, sumy = 0, sumz = 0;

    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        sumx += x;
        sumy += y;
        sumz += z;
    }

    if(sumx == 0 && sumy == 0 && sumz == 0)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
