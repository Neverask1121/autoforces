#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    string prev, curr;
    cin >> prev;

    int groups = 1;

    for(int i = 1; i < n; i++) {
        cin >> curr;
        if(curr != prev) {
            groups++;
        }
        prev = curr;
    }

    cout << groups;

    return 0;
}