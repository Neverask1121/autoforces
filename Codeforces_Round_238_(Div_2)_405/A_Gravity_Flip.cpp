#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    vector<int>a(t);
    for(int i = 0 ; i < t ; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for(int i = 0 ; i < t ; i++){
        cout << a[i] << " ";
    }
    return 0;
}