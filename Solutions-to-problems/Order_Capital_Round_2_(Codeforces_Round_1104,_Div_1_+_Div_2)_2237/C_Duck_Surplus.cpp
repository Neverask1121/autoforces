#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

void solve() {
    int m;
    cin >> m;

    vector<ll> arr(m);
    for(int i = 0; i < m; i++) {
        cin >> arr[i];
    }

    ll current_element = arr[0];

    for(int i = 1; i < m; i++) {
        if(current_element > arr[i]) {
            current_element += arr[i];
        } else {
            current_element = arr[i];
        }
    }

    cout << current_element << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }

    return 0;
}